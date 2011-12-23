/*
 * Mock_Window.cpp
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#ifndef MOCK_WINDOW_H
#define MOCK_WINDOW_H
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Mock_SurfaceLoader.h"
#include "Mock_SurfaceUtils.h"
#include "Display/Window.h"
#include "Display/Sprite.h"
class MockWindow : public Window  {
  public:
    MockWindow(MockSurfaceLoader* loader, MockSurfaceUtils* utils) : Window(loader, utils){

    }
    MOCK_METHOD3(showSprite, void(int x, int y, Sprite sprite));
    MOCK_METHOD4(clearRect, void(int x, int , size_t width, size_t height));
};
#endif
