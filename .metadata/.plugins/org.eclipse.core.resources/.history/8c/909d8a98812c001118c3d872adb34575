/*
 * Window.h
 *
 *  Created on: Dec 21, 2011
 *      Author: emint
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "SurfaceLoader.h"
#include "SDL/SDL.h"
#include "Display/Sprite.h"
#include "Display/SurfaceUtils.h"

class Window {
  public:
    Window(SurfaceLoader* surfaceLoader_, SurfaceUtils* surfaceUtils_);
    virtual ~Window();

    inline virtual size_t height() const {return windowSurface->h; }
    inline virtual size_t width() const {return windowSurface->w; }

    virtual void showSprite(int x, int y, Sprite sprite);
  private:
    SurfaceLoader* surfaceLoader;
    SurfaceUtils* surfaceUtils;
    size_t height_;
    size_t width_;

    SDL_Surface* windowSurface;
};

#endif /* WINDOW_H_ */
