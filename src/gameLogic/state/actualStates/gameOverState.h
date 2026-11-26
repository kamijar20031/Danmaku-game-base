#ifndef DANMAKU_GAMEOVER_STATE_H_
#define DANMAKU_GAMEOVER_STATE_H_

#include "gameState.h"

class GameOverState : public IGameState
{
    public:
        using IGameState::IGameState;
        void onInputEvent(InputEvent event) {}
        void update(float dt) {}
        void render(sf::RenderWindow& window) {}
};

#endif