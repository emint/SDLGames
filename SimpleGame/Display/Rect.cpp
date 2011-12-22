/*
 * Rect.cpp
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#include "Rect.h"

Rect::Rect() : x_(0), y_(0), height_(0), width_(0){
  // TODO Auto-generated constructor stub

}

Rect::Rect(int x, int y, size_t height, size_t width) : x_(x), y_(y), height_(height), width_(width){

}


Rect::~Rect() {
  // TODO Auto-generated destructor stub
}


SDL_Rect Rect::sdl(){
  SDL_Rect rect;
  rect.x = x_;
  rect.y = y_;
  rect.h = height_;
  rect.w = width_;
  return rect;
}

bool Rect::operator==(const Rect& other) const {
  return this->x_ == other.x() && this->y_ == other.y() &&
      this->width_ == other.width() && this->height_ == other.height();
}

bool Rect::operator!=(const Rect& other) const {
  return !(*this == other);
}
