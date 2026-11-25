#ifndef DANMAKU_STAGE_STATE_H_
#define DANMAKU_STAGE_STATE_H_

#include "gameState.h"

class StageState : public IGameState
{
    public:
        void onInputEvent(InputEvent event);
}

#endif