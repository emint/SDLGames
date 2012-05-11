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

void SurfaceUtils::spriteBlit(SDL_Rect position, Sprite src, SDL_Surface* target){
  SDL_Rect displayRect;
  displayRect.w = src.width();
  displayRect.h = src.height();
  displayRect.y = src.selectedXPosition();
  displayRect.x = src.selectedYPosition();

  SDL_BlitSurface(src.surface(), &displayRect, target, &position);
  SDL_Flip(target);
}

void SurfaceUtils::clearRect(SDL_Rect toClear, SDL_Surface* target){
  SDL_FillRect(target, &toClear, 0);
  SDL_Flip(target);
}
