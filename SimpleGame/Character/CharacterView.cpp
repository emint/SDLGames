/*
 * CharacterView.cpp
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#include "CharacterView.h"
#include <iostream>
using namespace std;

CharacterView::CharacterView(CharacterModel* model, Window* window) : model_(model), window_(window),
  curSpriteLocX(0), curSpriteLocY(0) {
}

CharacterView::~CharacterView() {
}

void CharacterView::display() {
  window_->clearRect(curSpriteLocX, curSpriteLocY, sprite->width(), sprite->height());
  int newX = model_->posX();
  int newY = model_->posY();

  window_->showSprite(newX, newY, *sprite);
  curSpriteLocX = newX;
  curSpriteLocY = newY;
  cout<<model_->posX()<<","<<model_->posY()<<endl;
}
