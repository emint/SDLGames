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

}
