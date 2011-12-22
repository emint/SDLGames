/*
 * Sprite.cpp
 *
 *  Created on: Dec 21, 2011
 *      Author: emint
 */

#include "Sprite.h"
#include <iostream>
#include "Exceptions/ResourceNotFoundException.h"
#include "Exceptions/InvalidArgumentException.h"

Sprite::Sprite(SurfaceLoader* surfaceLoader_) : surfaceLoader(surfaceLoader_),
spriteFileName(""), width_(16), height_(16), x(0), y(0) {

}

Sprite::~Sprite() {
  // TODO Auto-generated destructor stub
}

void Sprite::spriteIs(string fileName){
  spriteFileName = fileName;
  sprite = surfaceLoader->loadImage(spriteFileName);

  if (sprite == NULL){
    throw ResourceNotFoundException(fileName);
  }
}

void Sprite::selectedSpriteIs(size_t index){
  if (index*width_ >= (size_t) sprite->w) {
    throw InvalidArgumentException("Invalid sprite index specified.");
  }

  x = index*width_;
}
