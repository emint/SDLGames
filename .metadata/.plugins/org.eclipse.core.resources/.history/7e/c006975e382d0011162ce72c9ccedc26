/*
 * CharacterModelTest.cpp
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Mock_MovementControl.h"
#include "Character/CharacterModel.h"

using ::testing::Return;

TEST(CharacterModel, updatesPositionCorrectly){
  MockMovementControls controls;
  CharacterModel model(&controls);
  EXPECT_CALL(controls, xVelocity()).WillOnce(Return(10));
  EXPECT_CALL(controls, yVelocity()).WillOnce(Return(20));
  model.moveFor(10);
  EXPECT_EQ(100, model.posX());
  EXPECT_EQ(200, model.posY());
}
