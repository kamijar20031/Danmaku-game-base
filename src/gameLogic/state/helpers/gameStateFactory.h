#ifndef DANMAKU_GAME_STATE_FACTORY_H_
#define DANMAKU_GAME_STATE_FACTORY_H_

#include "stateTypes.h"
#include "stageState.h"
#include "menuState.h"
#include "pauseState.h"
#include "gameOverState.h"
class GameStateFactory
{
public:
    static std::unique_ptr<IGameState> create(GameStateType type, StateRequestHandler& requestHandler)
    {
        switch (type) 
        {
            case GameStateType::MainMenu:
                return std::make_unique<MenuState>(requestHandler);
            case GameStateType::Stage:
                return std::make_unique<StageState>(requestHandler);
            case GameStateType::Paused:
                return std::make_unique<PauseState>(requestHandler);
            case GameStateType::GameOver:
                return std::make_unique<GameOverState>(requestHandler);
        }
        return nullptr;
    }
};

#endif