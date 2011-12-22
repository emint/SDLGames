/*
 * WindowTest.cpp
 *
 *  Created on: Dec 21, 2011
 *      Author: emint
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "SDL/SDL.h"

#include "Mock_SurfaceLoader.h"
#include "Display/Window.h"
#include "Exceptions/ResourceNotFoundException.h"
#include "Mock_SurfaceUtils.h"

using ::testing::Return;
using ::testing::_;

TEST(Window, validInitialization) {
  SDL_Surface* validSurface = new SDL_Surface();
  MockSurfaceLoader loader;
  MockSurfaceUtils utils;

  EXPECT_CALL(loader, mainSurface(_, _, _, _)).WillOnce(Return(validSurface));

  EXPECT_NO_THROW(Window newWindow(&loader, &utils));
}

TEST(Window, invalidInitialization) {
  SDL_Surface* validSurface = NULL;
  MockSurfaceLoader loader;
  MockSurfaceUtils utils;

  EXPECT_CALL(loader, mainSurface(_, _, _, _)).WillOnce(Return(validSurface));

  EXPECT_THROW(Window newWindow(&loader, &utils), ResourceNotFoundException);
}
