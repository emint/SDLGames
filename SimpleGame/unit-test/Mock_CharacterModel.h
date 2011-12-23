/*
 * Mock_CharacterModel.cpp
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */
#ifndef MOCK_CHARACTERMODEL_H_
#define MOCK_CHARACTERMODEL_H_
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Character/CharacterModel.h"
#include "Controls/MovementControls.h"

class MockCharacterModel : public CharacterModel {
  public:
    MockCharacterModel(MovementControls* movement) : CharacterModel(movement){
    }
    MOCK_METHOD1(moveFor, void(Uint32 time));

    MOCK_CONST_METHOD0(posX, int());
    MOCK_CONST_METHOD0(posY, int());
};

#endif
