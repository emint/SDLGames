/*
 * Mock_SurfaceLoader.h
 *
 *  Created on: Dec 21, 2011
 *      Author: emint
 */
#ifndef MOCK_SURFACE_LOADER_H_
#define MOCK_SURFACE_LOADER_H_
#include "Display/SurfaceLoader.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

using namespace std;

class MockSurfaceLoader : public SurfaceLoader {
  public:
    MOCK_METHOD1(loadImage, SDL_Surface* (string fileName));
    MOCK_METHOD4(mainSurface, SDL_Surface* (int width, int height, int bpp, Uint32 flags));
};
#endif
