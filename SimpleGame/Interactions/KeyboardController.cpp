/*
 * KeyboardController.cpp
 *
 *  Created on: Dec 20, 2011
 *      Author: emint
 */

#include "KeyboardController.h"
#include <iostream>

using namespace std;

KeyboardController::~KeyboardController() {
}

void KeyboardController::keyEventIs(SDL_Event event) {
  MovementControls::MovementType movementEvent;
  bool moved = true;
  if (event.type == SDL_KEYDOWN) {
    if (event.key.keysym.sym == SDLK_UP){
      movementEvent = MovementControls::UP;
    } else if (event.key.keysym.sym == SDLK_DOWN) {
      movementEvent = MovementControls::DOWN;
    } else if (event.key.keysym.sym == SDLK_RIGHT) {
      movementEvent = MovementControls::RIGHT;
    } else if (event.key.keysym.sym == SDLK_LEFT) {
      movementEvent = MovementControls::LEFT;
    } else {
      cerr<<"Invalid key-down "<<event.key.keysym.sym<<" passed to "<<__FILE__<<endl;
      return;
    }
  } else if (event.type == SDL_KEYUP) {
    if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN) {
      movementEvent = MovementControls::UP_DOWN_STOP;
    } else if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT) {
      movementEvent = MovementControls::LEFT_RIGHT_STOP;
    } else {
      cerr<<"Invalid key-up "<<event.key.keysym.sym<<" passed to "<<__FILE__<<endl;
      return;
    }
  } else {
    moved = false;
  }

  if (moved){
    movementControls->movementIs(movementEvent);
  }
}
