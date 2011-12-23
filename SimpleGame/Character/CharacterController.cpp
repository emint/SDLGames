/*
 * CharacterController.cpp
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#include "CharacterController.h"

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
  model_->moveFor(passedTime);
  lastStateChange = curTime;
}
