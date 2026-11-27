#ifndef DANMAKU_NEXTSTAGE_STATE_H_
#define DANMAKU_NEXTSTAGE_STATE_H_

#include "gameState.h"
#include "hud.h"
extern HUDManager HUDTextures;
class NextStageState : public IGameState
{
    public:
        using IGameState::IGameState;
        void onInputEvent(InputEvent event);
        void update(float dt);
        void render(sf::RenderWindow& window);
};

#endif