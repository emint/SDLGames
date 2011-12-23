/*
 * TimeProvider.h
 *
 *  Created on: Dec 22, 2011
 *      Author: emint
 */

#ifndef TIMEPROVIDER_H_
#define TIMEPROVIDER_H_
#include "SDL/SDL.h"

class TimeProvider {
  public:
    TimeProvider();
    virtual ~TimeProvider();

    virtual inline Uint32 currentTimeInMs() const { return SDL_GetTicks(); }
};

#endif /* TIMEPROVIDER_H_ */
