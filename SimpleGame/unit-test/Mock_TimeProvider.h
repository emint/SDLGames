/*
 * Mock_TimeProvider.h
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Utils/TimeProvider.h"

class MockTimeProvider : public TimeProvider {
  public:
    MOCK_CONST_METHOD0(currentTimeInMs, Uint32());
};
