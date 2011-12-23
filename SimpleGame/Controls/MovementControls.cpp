/*
 * MovementControls.cpp
 *
 *  Created on: Dec 20, 2011
 *      Author: emint
 */

#include "MovementControls.h"

MovementControls::~MovementControls(){

}

void MovementControls::movementIs(MovementType movementType){
  switch (movementType){
    case UP:
      yVel = -1*yVelInc;
      break;
    case DOWN:
      yVel = yVelInc;
      break;
    case RIGHT:
      xVel = xVelInc;
      break;
    case LEFT:
      xVel = -1*xVelInc;
      break;
    case UP_DOWN_STOP:
      yVel = 0;
      break;
    case LEFT_RIGHT_STOP:
      xVel = 0;
      break;
  }
}
