#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * Application window parameters.
 */
#define APP_WIDTH 512
#define APP_HEIGHT 512
#define APP_BPP 32

/**
 * File names
 */
const string background = "vincent_back.PNG";
const string character = "loadingchars.png";

/**
 * Movement
 */
#define X_MOV 1
#define Y_MOV 1
#define MOV_RIGHT 0
#define MOV_LEFT 1
#define MOV_UP 2
#define MOV_DOWN 3
#define ANI_TIME 10
int last_move = 0;
int cur_move;
bool move_state[4];


/**
 * Char init location
 */
int char_x = 10;
int char_y = 10;

void
draw_pixel(SDL_Surface *screen, int x, int y, Uint8 R, Uint8 G, Uint8 B) {
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
draw_scene(SDL_Surface *screen) {
  srand(APP_WIDTH*APP_HEIGHT*rand());
  for (int x = 0; x < APP_WIDTH; x++) {
    for (int y = 0; y < APP_WIDTH; y++) {
      draw_pixel(screen, x, y, rand()%256, rand()%256, rand()%256);
    }
  }

  SDL_Flip(screen);
}

void
do_static(SDL_Surface* surface){
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

    draw_scene(surface);
  }
}


void
picture_display(SDL_Surface* surface){
  SDL_Surface* bg = NULL;
  bg = IMG_Load(background.c_str());
  if(bg == NULL){
    cout<<"Error loading<"<<background<<">.\n";
    return;
  }

  SDL_Surface* to_show = SDL_DisplayFormat(bg);
  SDL_FreeSurface(bg);



  SDL_BlitSurface(to_show, NULL, surface, NULL);

  SDL_Flip(surface);
  SDL_Delay(5000);
}

void
display_char(int x, int y, int width, int height, SDL_Surface* character_surface,
    SDL_Surface* screen){

  SDL_Rect clear_rect;
  clear_rect.x = x - X_MOV;
  clear_rect.y = y - Y_MOV;
  clear_rect.w = width+width/2;
  clear_rect.h = height+height/2;
  SDL_FillRect(screen, &clear_rect, 0);
  SDL_Rect sprite_loc;
  sprite_loc.x = 2*width;
  sprite_loc.y = 15*height;
  sprite_loc.w = width;
  sprite_loc.h = height;

  SDL_Rect screen_loc;
  screen_loc.x = x;
  screen_loc.y = y;
  SDL_BlitSurface(character_surface, &sprite_loc, screen, &screen_loc);
}

void
process_state(int &x, int &y){
  if(move_state[MOV_UP])
    y -= Y_MOV;
  else if(move_state[MOV_DOWN])
    y += Y_MOV;

  if(move_state[MOV_LEFT])
    x -= X_MOV;
  else if(move_state[MOV_RIGHT])
    x += X_MOV;
}

void
animate_char(SDL_Surface* character_surface, SDL_Surface* screen){
  bool close = false;

  while(!close){
    SDL_Event event;

    while(SDL_PollEvent(&event)){
      if (event.type == SDL_QUIT)
        close = true;

      if (event.type == SDL_KEYDOWN){
        if (event.key.keysym.sym == SDLK_UP)
          move_state[MOV_UP] = true;
        else if (event.key.keysym.sym == SDLK_DOWN)
          move_state[MOV_DOWN] = true;

        if(event.key.keysym.sym == SDLK_RIGHT)
          move_state[MOV_RIGHT] = true;
        else if (event.key.keysym.sym == SDLK_LEFT)
          move_state[MOV_LEFT] = true;
      }
      if (event.type == SDL_KEYUP){
              if (event.key.keysym.sym == SDLK_UP)
                move_state[MOV_UP] = false;
              else if (event.key.keysym.sym == SDLK_DOWN)
                move_state[MOV_DOWN] = false;

              if(event.key.keysym.sym == SDLK_RIGHT)
                move_state[MOV_RIGHT] = false;
              else if (event.key.keysym.sym == SDLK_LEFT)
                move_state[MOV_LEFT] = false;
            }
    }
    cur_move = SDL_GetTicks();

    if(cur_move - last_move > ANI_TIME){
      last_move = cur_move;
      process_state(char_x, char_y);
      display_char (char_x, char_y, 16, 16, character_surface, screen);
      SDL_Flip(screen);
    }
  }
}

void
move_char(SDL_Surface* surface){
  SDL_Surface* character_surf = NULL;
  character_surf = IMG_Load(character.c_str());

  if (character_surf == NULL){
    cout<<"Error loading <"<<character<<">.\n";
    return;
  }

  SDL_Surface* char_animate = SDL_DisplayFormat(character_surf);
  SDL_FreeSurface(character_surf);

  animate_char(char_animate, surface);
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
  if(argc < 2)
    return -1;

  if(strcmp(args[1], "static") == 0)
    do_static(surface);
  else if(strcmp(args[1], "image") == 0)
    picture_display(surface);
  else if(strcmp(args[1], "move") == 0)
    move_char(surface);

  atexit(SDL_Quit);
  return 0;
}
