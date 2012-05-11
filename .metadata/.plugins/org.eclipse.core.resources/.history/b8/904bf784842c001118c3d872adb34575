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
  SDL_Rect position;

  position.x = x;
  position.y = y;

  surfaceUtils->spriteBlit(position, sprite, windowSurface);
}

void Window::clearRect(int x, int y, size_t width, size_t height){
  SDL_Rect toClear;
  toClear.x = x;
  toClear.y = y;
  toClear.w = height;
  toClear.h = height;

  surfaceUtils->clearRect(toClear, windowSurface);
}
