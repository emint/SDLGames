/*
 * Mock_CharacterView.h
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */
#ifndef MOCK_CHARACTER_VIEW_H_
#define MOCK_CHARACTER_VIEW_H_

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Mock_Window.h"
#include "Mock_CharacterModel.h"

#include "Character/CharacterView.h"

class MockCharacterView : public CharacterView {
  public:
    MockCharacterView(MockCharacterModel* model, MockWindow* window) : CharacterView (model, window){

    }

    MOCK_METHOD0(display, void());
};
#endif
