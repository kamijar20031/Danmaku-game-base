#ifndef DANMAKU_PAUSE_STATE_H_
#define DANMAKU_PAUSE_STATE_H_

#include "gameState.h"
#include "hud.h"
#include "MenuOption.h"
#include "MenuStateModel.h"
#include "MenuFactory.h"

class PauseState : public IGameState
{
    int selection = 0;
    std::vector<MenuOption> options;
    std::unique_ptr<MenuStateModel> menuModel;
    public:
        PauseState(StateRequestHandler& handler);
        void incrementSelection();
        void decrementSelection();
        void processPauseSelection();
        void onInputEvent(InputEvent event);
        void update(float dt);
        void render(sf::RenderWindow& window);
        bool isTransparent() { return true; }
};

#endif