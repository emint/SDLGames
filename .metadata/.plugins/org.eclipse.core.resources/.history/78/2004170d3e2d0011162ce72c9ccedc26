/*
 * CharacterController.h
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#ifndef CHARACTERCONTROLLER_H_
#define CHARACTERCONTROLLER_H_
#include "Utils/TimeProvider.h"
#include "CharacterModel.h"
#include "CharacterView.h"

class CharacterController {
  public:
    CharacterController(TimeProvider* time, CharacterModel* model, CharacterView* view);
    virtual ~CharacterController();

    virtual void move();
  private:
    TimeProvider* time_;
    CharacterModel* model_;
    CharacterView* view_;
    Uint32 lastStateChange;
};

#endif /* CHARACTERCONTROLLER_H_ */
