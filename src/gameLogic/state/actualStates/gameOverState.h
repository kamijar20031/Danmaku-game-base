#ifndef DANMAKU_GAMEOVER_STATE_H_
#define DANMAKU_GAMEOVER_STATE_H_

#include "gameState.h"
#include "hud.h"

extern HUDManager HUDTextures;
class GameOverState : public IGameState
{
    int selection = 0;
    public:
        using IGameState::IGameState;
        void onInputEvent(InputEvent event);
        void update(float dt);
        void render(sf::RenderWindow& window);
        void incrementSelection();
        void decrementSelection();
        void processSelection();
};

#endif