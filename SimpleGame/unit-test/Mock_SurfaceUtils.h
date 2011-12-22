/*
 * Mock_SurfaceUtils.h
 *
 *  Created on: Dec 21, 2011
 *      Author: emint
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "SDL/SDL.h"
#include "Display/SurfaceUtils.h"
#include "Display/Sprite.h"

class MockSurfaceUtils : public SurfaceUtils {
  public:
    MOCK_METHOD4(spriteBlit, void(SDL_Rect clear, SDL_Rect display, Sprite sprite, SDL_Surface* target));
};
