#ifndef DANMAKU_STATE_REQUEST_OBSERVER_H_
#define DANMAKU_STATE_REQUEST_OBSERVER_H_

#include "stateTypes.h"

class IStateRequestObserver
{
    public:
        virtual ~IStateRequestObserver() = default;
        virtual void onRequestChangeEvent(GameStateTypeCommand t) = 0;
};

#endif