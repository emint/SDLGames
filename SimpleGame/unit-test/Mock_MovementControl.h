/*
 * Mock_MovementControl.cpp
 *
 *  Created on: Dec 20, 2011
 *      Author: emint
 */
#ifndef MOCK_MOVEMENT_CONTROL_H_
#define MOCK_MOVEMENT_CONTROL_H_
#include "Controls/MovementControls.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockMovementControls : public MovementControls {
  public:
    MOCK_CONST_METHOD0(xVelocity, float());
    MOCK_CONST_METHOD0(yVelocity, float());
    MOCK_METHOD1(movementIs, void(MovementControls::MovementType movementType));
};
#endif
