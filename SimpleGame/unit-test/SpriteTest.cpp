#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "SDL/SDL.h"

#include "Mock_SurfaceLoader.h"
#include "Display/Sprite.h"
#include "Exceptions/ResourceNotFoundException.h"
#include "Exceptions/InvalidArgumentException.h"

using namespace std;
using ::testing::Return;

TEST(Sprite, loadValidSprite) {
  SDL_Surface* validSurface = new SDL_Surface();
  MockSurfaceLoader loader;
  string imgName = "name";

  EXPECT_CALL(loader, loadImage(imgName)).WillOnce(Return(validSurface));

  Sprite sprite(&loader);
  EXPECT_NO_THROW(sprite.spriteIs(imgName));
}

TEST(Sprite, loadInvalidSprite) {
  MockSurfaceLoader loader;
  string imgName = "name";
  SDL_Surface* nullSurface = NULL;
  EXPECT_CALL(loader, loadImage(imgName)).WillOnce(Return(nullSurface));

  Sprite sprite(&loader);
  EXPECT_THROW(sprite.spriteIs(imgName), ResourceNotFoundException);
}

TEST(Sprite, selectingValidSprite) {
  SDL_Surface* validSurface = new SDL_Surface();
  validSurface->w = 80;
  validSurface->h = 80;
  MockSurfaceLoader loader;
  string imgName = "name";
  EXPECT_CALL(loader, loadImage(imgName)).WillOnce(Return(validSurface));

  Sprite sprite(&loader);
  EXPECT_NO_THROW(sprite.spriteIs(imgName));

  EXPECT_NO_THROW(sprite.selectedSpriteIs(3));
}

TEST(Sprite, selectingInvalidSprite) {
  SDL_Surface* validSurface = new SDL_Surface();
  validSurface->w = 80;
  validSurface->h = 80;
  MockSurfaceLoader loader;
  string imgName = "name";
  EXPECT_CALL(loader, loadImage(imgName)).WillOnce(Return(validSurface));

  Sprite sprite(&loader);
  EXPECT_NO_THROW(sprite.spriteIs(imgName));

  EXPECT_THROW(sprite.selectedSpriteIs(5), InvalidArgumentException);
}
