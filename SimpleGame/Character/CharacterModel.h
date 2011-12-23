/*
 * CharacterModel.h
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#ifndef CHARACTERMODEL_H_
#define CHARACTERMODEL_H_

#include "Controls/MovementControls.h"
#include "Utils/TimeProvider.h"

class CharacterModel {
  public:
    CharacterModel(MovementControls* controls);
    virtual ~CharacterModel();

    virtual void moveFor(Uint32 timeToMove);

    virtual inline int posX() const { return pos_x; }
    virtual inline int posY() const { return pos_y; }
  private:
    MovementControls* controls_;

    int pos_x;
    int pos_y;
};

#endif /* CHARACTERMODEL_H_ */
