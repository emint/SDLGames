#include "SDL/SDL.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * Application window parameters.
 */
#define APP_WIDTH 512
#define APP_HEIGHT 512
#define APP_BPP 32

void
DrawPixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B) {
  Uint32 color = SDL_MapRGB(screen->format, R, G, B);
  switch (screen->format->BytesPerPixel) {
  case 1: // Assuming 8-bpp
  {
    Uint8 *bufp;
    bufp = (Uint8 *) screen->pixels + y * screen->pitch + x;
    *bufp = color;
  }
    break;
  case 2: // Probably 15-bpp or 16-bpp
  {
    Uint16 *bufp;
    bufp = (Uint16 *) screen->pixels + y * screen->pitch / 2 + x;
    *bufp = color;
  }
    break;
  case 3: // Slow 24-bpp mode, usually not used
  {
    Uint8 *bufp;
    bufp = (Uint8 *) screen->pixels + y * screen->pitch + x * 3;
    if (SDL_BYTEORDER == SDL_LIL_ENDIAN) {
      bufp[0] = color;
      bufp[1] = color >> 8;
      bufp[2] = color >> 16;
    }
    else {
      bufp[2] = color;
      bufp[1] = color >> 8;
      bufp[0] = color >> 16;
    }
  }
    break;
  case 4: // Probably 32-bpp
  {
    Uint32 *bufp;
    bufp = (Uint32 *) screen->pixels + y * screen->pitch / 4 + x;
    *bufp = color;
  }
    break;
  }
}

void
DrawScene(SDL_Surface *screen) {
  srand(APP_WIDTH*APP_HEIGHT*rand());
  for (int x = 0; x < APP_WIDTH; x++) {
    for (int y = 0; y < APP_WIDTH; y++) {
      DrawPixel(screen, x, y, rand()%256, rand()%256, rand()%256);
    }
  }

  SDL_Flip(screen);
}

int
main(int argc, char* args[]) {
  //Start SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    cout << "Error initializing SDL. " << SDL_GetError();
    return -1;
  }

  SDL_Surface* surface = SDL_SetVideoMode(APP_WIDTH, APP_HEIGHT, APP_BPP,
      SDL_HWSURFACE | SDL_DOUBLEBUF);

  if (!surface) {
    cout << "Error initializing main canvas with size " << APP_WIDTH << "x"
        << APP_HEIGHT << ". Error: " << SDL_GetError();
    return -1;
  }
  int done = 0;

  while (done == 0) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = 1;
      }

      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_ESCAPE) {
          done = 1;
        }
      }
    }

    DrawScene(surface);
  }
  atexit(SDL_Quit);
  return 0;
}
