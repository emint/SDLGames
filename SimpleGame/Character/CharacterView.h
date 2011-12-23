/*
 * CharacterView.h
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#ifndef CHARACTERVIEW_H_
#define CHARACTERVIEW_H_

#include "Display/Window.h"
#include "CharacterModel.h"
#include "Display/Sprite.h"
class CharacterView {
  public:
    CharacterView(CharacterModel* model, Window* window);
    virtual ~CharacterView();

    virtual inline void spriteIs(Sprite* sprite) { sprite_ = sprite; }

    virtual void setSpriteAndDisplay(Sprite* sprite, int x, int y);

    virtual void display();

    virtual int curSpriteLocX() const;
    virtual int curSpriteLocY() const;
  private:
    CharacterModel* model_;
    Window* window_;
    Sprite* sprite_;

    int curSpriteLocX_;
    int curSpriteLocY_;

};

#endif /* CHARACTERVIEW_H_ */
