/*
 * CharacterController.cpp
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#include "CharacterController.h"
#include <iostream>
using namespace std;

CharacterController::CharacterController(TimeProvider* time, CharacterModel* model,
    CharacterView* view) : time_(time), model_(model), view_(view) {
  lastStateChange = time->currentTimeInMs();
}


CharacterController::~CharacterController() {
  // TODO Auto-generated destructor stub
}

void CharacterController::move() {
  Uint32 curTime = time_->currentTimeInMs();
  Uint32 passedTime = curTime - lastStateChange;
  cout<<"cur "<<curTime<<" last "<<lastStateChange<<endl;
  //TODO FIX ME This is a hack!
  model_->moveFor(passedTime/10);
  lastStateChange = curTime;
}

void CharacterController::display() {
  if (view_->curSpriteLocX() != model_->posX() || view_->curSpriteLocY() != model_->posY()){
    view_->display();
  }
}
