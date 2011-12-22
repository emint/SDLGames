/*
 * SurfaceUtils.cpp
 *
 *  Created on: Dec 21, 2011
 *      Author: emint
 */

#include "SurfaceUtils.h"

SurfaceUtils::SurfaceUtils() {
  // TODO Auto-generated constructor stub

}

SurfaceUtils::~SurfaceUtils() {
  // TODO Auto-generated destructor stub
}

void SurfaceUtils::spriteBlit(Rect position, Sprite src, SDL_Surface* target){
  SDL_Rect displayRect;
  displayRect.w = src.width();
  displayRect.h = src.height();
  displayRect.y = src.selectedXPosition();
  displayRect.x = src.selectedYPosition();

  SDL_Rect sdlPos = position.sdl();

  SDL_BlitSurface(src.surface(), &displayRect, target, &sdlPos);
  SDL_Flip(target);
}

void SurfaceUtils::clearRect(Rect toClear, SDL_Surface* target){
  SDL_Rect sdlClear = toClear.sdl();
  SDL_FillRect(target, &sdlClear, 0);
  SDL_Flip(target);
}
