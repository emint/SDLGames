/*
 * MovementControls.h
 *
 *  Created on: Dec 20, 2011
 *      Author: emint
 */

#ifndef MOVEMENTCONTROLS_H_
#define MOVEMENTCONTROLS_H_

class MovementControls {
  public:
    MovementControls() : xVel(0), yVel(0), xVelInc(2), yVelInc(2) {
    }
    virtual ~MovementControls();

    enum MovementType {
      UP,
      DOWN,
      LEFT,
      RIGHT,
      UP_DOWN_STOP,
      LEFT_RIGHT_STOP
    };

    virtual inline float xVelocity() const { return xVel; }
    virtual inline float yVelocity() const { return yVel; }

    virtual void movementIs(MovementType movementType);

  private:
    float xVel;
    float yVel;

    float xVelInc;
    float yVelInc;
};

#endif /* MOVEMENTCONTROLS_H_ */
