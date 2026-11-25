#pragma once
#include "entity.h"
#include "danmaku.h"
#include "inputHandler.h"
class Player :public Entity
{
    float xSpeed;
    float ySpeed;

public:
    bool shooting;
    Player();
    bool isDead();
    void onInputEvent(InputEvent event);
    char movingDirection() { if (this->xSpeed > 0) return 'R'; else if (this->xSpeed < 0) return 'L'; else return 'N'; }
    void process(float dt);
    void destroy(char full = 'n');
    void doWhenReady(float dt);
    void setToStartLocation() { this->x = GAME_WIDTH / 2; this->y = GAME_HEIGHT * 3 / 4; }
    void playerUpdate(float dt);
};