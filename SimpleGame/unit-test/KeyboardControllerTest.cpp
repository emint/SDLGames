/*
 * KeyboardControllerTest.cpp
 *
 *  Created on: Dec 20, 2011
 *      Author: emint
 */

#include "Interactions/KeyboardController.h"
#include "Mock_MovementControl.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "SDL/SDL.h"

SDL_Event makeEvent(Uint8 type, const SDLKey key){
  SDL_keysym keysm;
  keysm.sym = key;

  SDL_KeyboardEvent keyEvent;
  keyEvent.keysym = keysm;

  SDL_Event event;
  event.key = keyEvent;
  event.type = type;

  return event;
}

TEST(KeyboardController, upKeyPressed){
  MockMovementControls mockMovementControls;
  KeyboardController controller(&mockMovementControls);

  EXPECT_CALL(mockMovementControls, movementIs(MovementControls::UP));

  SDL_Event event = makeEvent(SDL_KEYDOWN, SDLK_UP);

  controller.keyEventIs(event);
}

TEST(KeyboardController, downKeyPressed){
  MockMovementControls mockMovementControls;
  KeyboardController controller(&mockMovementControls);

  EXPECT_CALL(mockMovementControls, movementIs(MovementControls::DOWN));

  SDL_Event event = makeEvent(SDL_KEYDOWN, SDLK_DOWN);

  controller.keyEventIs(event);
}

TEST(KeyboardController, leftKeyPressed){
  MockMovementControls mockMovementControls;
  KeyboardController controller(&mockMovementControls);

  EXPECT_CALL(mockMovementControls, movementIs(MovementControls::LEFT));

  SDL_Event event = makeEvent(SDL_KEYDOWN, SDLK_LEFT);

  controller.keyEventIs(event);
}

TEST(KeyboardController, rightKeyPressed){
  MockMovementControls mockMovementControls;
  KeyboardController controller(&mockMovementControls);

  EXPECT_CALL(mockMovementControls, movementIs(MovementControls::RIGHT));

  SDL_Event event = makeEvent(SDL_KEYDOWN, SDLK_RIGHT);

  controller.keyEventIs(event);
}

TEST(KeyboardController, upKeyReleased){
  MockMovementControls mockMovementControls;
  KeyboardController controller(&mockMovementControls);

  EXPECT_CALL(mockMovementControls, movementIs(MovementControls::UP_DOWN_STOP));

  SDL_Event event = makeEvent(SDL_KEYUP, SDLK_UP);

  controller.keyEventIs(event);
}

TEST(KeyboardController, downKeyReleased){
  MockMovementControls mockMovementControls;
  KeyboardController controller(&mockMovementControls);

  EXPECT_CALL(mockMovementControls, movementIs(MovementControls::UP_DOWN_STOP));

  SDL_Event event = makeEvent(SDL_KEYUP, SDLK_DOWN);

  controller.keyEventIs(event);
}

TEST(KeyboardController, leftKeyReleased){
  MockMovementControls mockMovementControls;
  KeyboardController controller(&mockMovementControls);

  EXPECT_CALL(mockMovementControls, movementIs(MovementControls::LEFT_RIGHT_STOP));

  SDL_Event event = makeEvent(SDL_KEYUP, SDLK_LEFT);

  controller.keyEventIs(event);
}

TEST(KeyboardController, rightKeyReleased){
  MockMovementControls mockMovementControls;
  KeyboardController controller(&mockMovementControls);

  EXPECT_CALL(mockMovementControls, movementIs(MovementControls::LEFT_RIGHT_STOP));

  SDL_Event event = makeEvent(SDL_KEYUP, SDLK_RIGHT);

  controller.keyEventIs(event);
}
