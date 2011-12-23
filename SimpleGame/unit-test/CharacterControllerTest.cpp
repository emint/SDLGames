/*
 * CharacterControllerTest.cpp
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Character/CharacterController.h"
#include "Mock_CharacterModel.h"
#include "Mock_CharacterView.h"
#include "Mock_TimeProvider.h"
#include "Mock_MovementControl.h"

#include <iostream>
using namespace std;
using ::testing::Return;

TEST(CharacterController, initializedTime){
  MockMovementControls mockMovement;
  MockCharacterModel mockModel(&mockMovement);
  MockCharacterView mockView;
  MockTimeProvider time;
  EXPECT_CALL(time, currentTimeInMs()).WillOnce(Return(0));
  CharacterController controller(&time, &mockModel, &mockView);
}

TEST(CharacterController, callsMoveProperly) {
  MockMovementControls mockMovement;
  MockCharacterModel mockModel(&mockMovement);
  MockCharacterView mockView;
  MockTimeProvider time;
  EXPECT_CALL(time, currentTimeInMs()).WillOnce(Return(0)).WillOnce(Return(100));
  EXPECT_CALL(mockModel, moveFor(100));
  CharacterController controller(&time, &mockModel, &mockView);
  controller.move();
}
