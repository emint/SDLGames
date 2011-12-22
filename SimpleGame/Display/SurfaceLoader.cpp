/*
 * SurfaceLoader.cpp
 *
 *  Created on: Dec 21, 2011
 *      Author: emint
 */

#include "SurfaceLoader.h"

SurfaceLoader::SurfaceLoader() {

}

SurfaceLoader::~SurfaceLoader() {
}

SDL_Surface* SurfaceLoader::loadImage(string imageName){
  SDL_Surface* character_surf = NULL;
  character_surf = IMG_Load(imageName.c_str());

  if (character_surf == NULL){
    return NULL;
  }

  SDL_Surface* image = SDL_DisplayFormat(character_surf);
  SDL_FreeSurface(character_surf);
  return image;
}

SDL_Surface* SurfaceLoader::mainSurface(int width, int height, int bpp, Uint32 flags){
  SDL_Surface* surface = SDL_SetVideoMode(width, height, bpp, flags);
  return surface;
}
