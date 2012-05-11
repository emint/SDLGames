/*
 * Window.cpp
 *
 *  Created on: Dec 21, 2011
 *      Author: emint
 */

#include "Window.h"
#include "Exceptions/ResourceNotFoundException.h"

Window::Window(SurfaceLoader* surfaceLoader_, SurfaceUtils* surfaceUtils_) : surfaceLoader(surfaceLoader_),
  surfaceUtils(surfaceUtils_), height_(512), width_(512) {
  windowSurface = surfaceLoader_->mainSurface(width_, height_, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  if (windowSurface == NULL){
    throw ResourceNotFoundException("A window main window");
  }
}

Window::~Window() {
  // TODO Auto-generated destructor stub
}

void Window::showSprite(int x, int y, Sprite sprite){
  SDL_Rect clearRect;
  SDL_Rect position;

  clearRect.x = x-1;
  clearRect.y = y-1;
  clearRect.h = 1.5*sprite.height();
  clearRect.w = 1.5*sprite.width();

  position.x = x;
  position.y = y;

  surfaceUtils->spriteBlit(clearRect, position, sprite, windowSurface);
}
