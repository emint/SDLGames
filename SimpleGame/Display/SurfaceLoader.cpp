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
  SDL_Surface* image = IMG_Load(imageName.c_str());

  return image;
}

SDL_Surface* SurfaceLoader::mainSurface(int width, int height, int bpp, Uint32 flags){
  SDL_Surface* surface = SDL_SetVideoMode(width, height, bpp, flags);
  return surface;
}
