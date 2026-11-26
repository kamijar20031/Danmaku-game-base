#ifndef DANMAKU_MENU_STATE_H_
#define DANMAKU_MENU_STATE_H_

#include "gameState.h"

class MenuState : public IGameState
{
    public:
        void onInputEvent(InputEvent event);
}

#endif