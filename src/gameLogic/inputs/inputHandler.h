#ifndef DANMAKU_INPUT_HANDLER_H_
#define DANMAKU_INPUT_HANDLER_H_

#include "inputObserver.h"
#include <vector>
#include "constants.h"

class InputHandler
{
    std::vector<IInputObserver*> observers;

public:
    void subscribe(IInputObserver* o)
    {
        observers.push_back(o);
    }

    void unsubscribe(IInputObserver* o)
    {
        std::erase(observers, o);
    }

    void notify(InputEvent e)
    {
        for (auto* o : observers)
            o->onInputEvent(e);
    }

    void process(const sf::Event& event);
};

#endif