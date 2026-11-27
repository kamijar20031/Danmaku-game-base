#ifndef DANMAKU_GAME_STATE_MANAGER_H_
#define DANMAKU_GAME_STATE_MANAGER_H_

#include "gameState.h"
#include "inputHandler.h"
#include "stateRequestHandler.h"
#include <memory>
#include "gameStateFactory.h"

class GameStateManager : public IInputObserver, public IStateRequestObserver
{
    std::vector<std::unique_ptr<IGameState>> states;
    InputHandler& inputHandler;
    StateRequestHandler& requestHandler;
public:
    GameStateManager(InputHandler& handler, StateRequestHandler& requestHandler) : inputHandler{handler}, requestHandler{requestHandler}
    {
        inputHandler.subscribe(this);
        requestHandler.subscribe(this);
    }
    ~GameStateManager()
    {
        inputHandler.unsubscribe(this);
        requestHandler.unsubscribe(this);
    }

    void process(float dt)
    {
        if (!states.empty()) states.back()->update(dt);
    }
    void render(sf::RenderWindow& window)
    {
        if (!states.empty()) 
        {
            int firstVisible = states.size() - 1;
            while (firstVisible>0 && states[firstVisible]->isTransparent())
                firstVisible--;
            for (int i = firstVisible; i< states.size(); i++)
                states[i]->render(window);

        }

    }

    void pushState(std::unique_ptr<IGameState> state)
    {
        states.push_back(std::move(state));
    }
    void popState()
    {
        if (!states.empty())
            states.pop_back();
    }
    void replaceState(std::unique_ptr<IGameState> state)
    {
        popState();
        states.push_back(std::move(state));
    }


    void onInputEvent(InputEvent event)
    {
        if (!states.empty()) states.back()->onInputEvent(event);
    }
    

    void onRequestChangeEvent(GameStateTypeCommand cmd);
};

#endif