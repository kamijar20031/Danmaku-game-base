#include "stateManager.h"

void GameStateManager::onRequestChangeEvent(GameStateTypeCommand cmd)
{
    switch (cmd)
    {
        
        case GameStateTypeCommand::StartStage: 
        {
            pushState(GameStateFactory::create(GameStateType::Stage, requestHandler));
            break;
        }
        case GameStateTypeCommand::Pause: 
        {
            pushState(GameStateFactory::create(GameStateType::Paused, requestHandler));
            break;
        }
        case GameStateTypeCommand::Unpause: 
        {
            popState();
            break;
        }
        case GameStateTypeCommand::StartMainMenu:
        {
            pushState(GameStateFactory::create(GameStateType::MainMenu, requestHandler));
            break;
        }
        case GameStateTypeCommand::Restart:
        {
            popState();
            pushState(GameStateFactory::create(GameStateType::Stage, requestHandler));
            break;
        }
    }
}