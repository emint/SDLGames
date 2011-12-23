/*
 * Mock_CharacterController.h
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */
#ifndef MOCK_CHARACTER_CONTROLLER_H_
#define MOCK_CHARACTER_CONTROLLER_H_

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Character/CharacterController.h"
#include "Mock_CharacterModel.h"
#include "Mock_CharacterView.h"
#include "Mock_TimeProvider.h"
#include "Controls/MovementControls.h"

class MockCharacterController : public CharacterController {
  public:
    MockCharacterController(MockTimeProvider* time, MockCharacterModel* model, MockCharacterView* view) :
      CharacterController(time, model, view){

    }

    MockCharacterController() :
      CharacterController(new MockTimeProvider(), NULL, NULL){

    }

    MOCK_METHOD0(move, void());
};

#endif
