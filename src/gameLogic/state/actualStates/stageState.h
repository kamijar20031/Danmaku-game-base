#ifndef DANMAKU_STAGE_STATE_H_
#define DANMAKU_STAGE_STATE_H_

#include "gameState.h"
#include "player.h"
#include "board.h"

class StageState : public IGameState
{
    // std::unique_ptr<Player> player;
    Board gameBoard;
public:
    using IGameState::IGameState;
    void onInputEvent(InputEvent event);
    void update(float dt);
    void render(sf::RenderWindow& window);
};

#endif