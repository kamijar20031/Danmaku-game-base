#ifndef DANMAKU_GAME_STATE_H_
#define DANMAKU_GAME_STATE_H_

#include "inputEvent.h"

class IGameState
{
    public:
        virtual ~IGameState() = default;
        virtual void onInputEvent(InputEvent event) = 0;
}

#endif