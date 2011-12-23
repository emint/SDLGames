/*
 * Mock_TimeProvider.h
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */
#ifndef MOCK_TIME_PROVIDER_H_
#define MOCK_TIME_PROVIDER_H_

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Utils/TimeProvider.h"

class MockTimeProvider : public TimeProvider {
  public:
    MOCK_CONST_METHOD0(currentTimeInMs, Uint32());
};

#endif
