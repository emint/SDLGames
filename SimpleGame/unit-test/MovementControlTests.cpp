/*
 * MovementControlTests.cpp
 *
 *  Created on: Dec 20, 2011
 *      Author: emint
 */

#include <gtest/gtest.h>
#include "Controls/MovementControls.h"

TEST(MovementControls, upKey){
  MovementControls moveControls;

  moveControls.movementIs(MovementControls::UP);

  EXPECT_EQ(moveControls.yVelocity(), -2);
  EXPECT_EQ(moveControls.xVelocity(), 0);

  moveControls.movementIs(MovementControls::UP_DOWN_STOP);

  EXPECT_EQ(moveControls.yVelocity(), 0);
  EXPECT_EQ(moveControls.xVelocity(), 0);
}

TEST(MovementControls, downKey){
  MovementControls moveControls;

  moveControls.movementIs(MovementControls::DOWN);

  EXPECT_EQ(moveControls.yVelocity(), 2);
  EXPECT_EQ(moveControls.xVelocity(), 0);

  moveControls.movementIs(MovementControls::UP_DOWN_STOP);

  EXPECT_EQ(moveControls.yVelocity(), 0);
  EXPECT_EQ(moveControls.xVelocity(), 0);
}

TEST(MovementControls, leftKey){
  MovementControls moveControls;

  moveControls.movementIs(MovementControls::LEFT);

  EXPECT_EQ(moveControls.xVelocity(), -2);
  EXPECT_EQ(moveControls.yVelocity(), 0);

  moveControls.movementIs(MovementControls::LEFT_RIGHT_STOP);

  EXPECT_EQ(moveControls.xVelocity(), 0);
  EXPECT_EQ(moveControls.yVelocity(), 0);
}

TEST(MovementControls, rightKey){
  MovementControls moveControls;

  moveControls.movementIs(MovementControls::RIGHT);

  EXPECT_EQ(moveControls.xVelocity(), 2);
  EXPECT_EQ(moveControls.yVelocity(), 0);

  moveControls.movementIs(MovementControls::LEFT_RIGHT_STOP);

  EXPECT_EQ(moveControls.xVelocity(), 0);
  EXPECT_EQ(moveControls.yVelocity(), 0);
}

TEST(MovementControls, twoKeys){
  MovementControls moveControls;

  moveControls.movementIs(MovementControls::RIGHT);
  moveControls.movementIs(MovementControls::DOWN);

  EXPECT_EQ(moveControls.xVelocity(), 2);
  EXPECT_EQ(moveControls.yVelocity(), 2);

  moveControls.movementIs(MovementControls::LEFT_RIGHT_STOP);

  EXPECT_EQ(moveControls.xVelocity(), 0);
  EXPECT_EQ(moveControls.yVelocity(), 2);
}
