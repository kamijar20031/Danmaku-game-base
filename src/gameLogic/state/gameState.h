#ifndef DANMAKU_GAME_STATE_H_
#define DANMAKU_GAME_STATE_H_

#include "inputEvent.h"
#include "constants.h"
#include "stateRequestHandler.h"

class IGameState
{
    protected:
        StateRequestHandler& handler;
    public:
        IGameState(StateRequestHandler& handler) : handler(handler) {}
        virtual ~IGameState() = default;
        virtual void onInputEvent(InputEvent event) = 0;
        virtual void update(float dt) = 0;
        virtual void render(sf::RenderWindow& window) = 0;
        virtual bool isTransparent() {return false;}

};

#endif