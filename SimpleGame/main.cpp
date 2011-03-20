#include "SDL/SDL.h"
#include <iostream>

using namespace std;

/**
 * Application window parameters.
 */
#define APP_WIDTH 512
#define APP_HEIGHT 512
#define APP_BPP 32

int
main(int argc, char* args[]) {
  //Start SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    cout << "Error initializing SDL. " << SDL_GetError();
    SDL_Quit();
    return -1;
  }

  SDL_Surface* surface = SDL_SetVideoMode(APP_WIDTH, APP_HEIGHT, APP_BPP,
      SDL_HWSURFACE|SDL_DOUBLEBUF);

  if(!surface){
    cout<<"Error initializing main canvas with size "<<APP_WIDTH<<"x"
        <<APP_HEIGHT<<". Error: "<<SDL_GetError();
    SDL_Quit();
    return -1;
  }

  //Quit SDL
  SDL_Quit();

  return 0;
}
