#ifndef DANMAKU_MENU_STATE_H_
#define DANMAKU_MENU_STATE_H_

#include "gameState.h"
#include "hud.h"
extern HUDManager HUDTextures;
class MenuState : public IGameState
{
    int selection = 0;
    public:
        using IGameState::IGameState;
        void incrementSelection();
        void decrementSelection();
        void onInputEvent(InputEvent event);
        void update(float dt);
        void render(sf::RenderWindow& window);
        void processMenuSelection();
};

#endif