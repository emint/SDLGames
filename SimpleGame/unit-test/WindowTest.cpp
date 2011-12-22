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

#include "Display/Rect.h"
#include "Display/Window.h"
#include "Display/Sprite.h"

#include "Exceptions/ResourceNotFoundException.h"

#include "Mock_SurfaceLoader.h"
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
  SDL_Surface* invalidSurface = NULL;
  MockSurfaceLoader loader;
  MockSurfaceUtils utils;

  EXPECT_CALL(loader, mainSurface(_, _, _, _)).WillOnce(Return(invalidSurface));

  EXPECT_THROW(Window newWindow(&loader, &utils), ResourceNotFoundException);
}

TEST(Window, spriteBlit) {
  SDL_Surface* validSurface = new SDL_Surface();
  MockSurfaceLoader loader;
  MockSurfaceUtils utils;

  Sprite sprite(&loader);
  sprite.widthIs(16);
  sprite.heightIs(16);
  EXPECT_CALL(loader, mainSurface(_, _, _, _)).WillOnce(Return(validSurface));
  int x_pos = 4, y_pos = 5;

  Rect rect;
  rect.xIs(x_pos);
  rect.yIs(y_pos);

  EXPECT_CALL(utils, spriteBlit( rect, _, _));
  Window newWindow(&loader, &utils);

  newWindow.showSprite(x_pos, y_pos, sprite);
}

TEST(Window, clearRect){
  SDL_Surface* validSurface = new SDL_Surface();
  MockSurfaceLoader loader;
  MockSurfaceUtils utils;

  EXPECT_CALL(loader, mainSurface(_, _, _, _)).WillOnce(Return(validSurface));
  int x_pos = 4, y_pos = 5, width = 16, height = 16;
  Rect clear(x_pos, y_pos, width, height);
  EXPECT_CALL(utils, clearRect(clear,_));
  Window newWindow(&loader, &utils);

  newWindow.clearRect(x_pos, y_pos, width, height);
}
