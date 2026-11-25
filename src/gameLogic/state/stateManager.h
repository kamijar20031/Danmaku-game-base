#ifndef DANMAKU_GAME_STATE_MANAGER_H_
#define DANMAKU_GAME_STATE_MANAGER_H_

#include "gameState.h"
#include "inputHandler.h"

class GameStateManager : public IInputObserver
{
    std::unique_ptr<IGameState> currentState;
    InputHandler& handler;
public:
    GameStateManager::GameStateManager(InputHandler& handler) : handler{handler} {}
    void setState(std::unique_ptr<IGameState> state)
    {
        currentState = std::move(state);
    }

    void onInputEvent(InputEvent event)
    {
        if (currentState) currentState->onInputEvent(event);
    }

}

#endif