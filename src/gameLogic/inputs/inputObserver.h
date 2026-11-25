#ifndef DANMAKU_INPUT_OBSERVER_H_
#define DANMAKU_INPUT_OBSERVER_H_

#include "inputEvent.h"

class IInputObserver
{
    public:
        virtual ~IInputObserver() = default;
        virtual void onInputEvent(InputEvent event) = 0;
};

#endif