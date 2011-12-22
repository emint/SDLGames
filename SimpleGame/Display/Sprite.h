/*
 * Sprite.h
 *
 *  Created on: Dec 21, 2011
 *      Author: emint
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SurfaceLoader.h"

using namespace std;

class Sprite {
  public:
    Sprite(SurfaceLoader* surfaceLoader_);
    virtual ~Sprite();

    inline virtual size_t height() const {return height_;}
    inline virtual size_t width() const {return width_;}

    inline virtual void heightIs(size_t height) { height_ = height; }
    inline virtual void widthIs (size_t width) { width_ = width; }

    inline virtual SDL_Surface* surface() { return sprite; }

    virtual void selectedSpriteIs(size_t index);

    inline virtual size_t selectedXPosition() { return x; }
    inline virtual size_t selectedYPosition() { return y; }

    virtual void spriteIs(string fileName);
  private:
    SurfaceLoader* surfaceLoader;
    string spriteFileName;

    size_t width_;
    size_t height_;
    SDL_Surface* sprite;

    size_t x;
    size_t y;
};

#endif /* SPRITE_H_ */
