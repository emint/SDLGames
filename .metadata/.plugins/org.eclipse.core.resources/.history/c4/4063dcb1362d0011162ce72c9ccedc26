/*
 * CharacterModel.cpp
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#include "CharacterModel.h"

CharacterModel::CharacterModel(MovementControls* movementControls) :
  controls_(movementControls), pos_x(0), pos_y(0){
  // TODO Auto-generated constructor stub

}

CharacterModel::~CharacterModel() {
  // TODO Auto-generated destructor stub
}

void CharacterModel::moveFor(Uint32 time) {
  pos_x += time*controls_->xVelocity();
  pos_y += time*controls_->yVelocity();
}
