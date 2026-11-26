#ifndef DANMAKU_PAUSE_STATE_H_
#define DANMAKU_PAUSE_STATE_H_

#include "gameState.h"
#include "hud.h"
extern HUDManager HUDTextures;
class PauseState : public IGameState
{
    int selection = 0;
    public:
        using IGameState::IGameState;
        void incrementSelection();
        void decrementSelection();
        void processPauseSelection();
        void onInputEvent(InputEvent event);
        void update(float dt);
        void render(sf::RenderWindow& window);
};

#endif