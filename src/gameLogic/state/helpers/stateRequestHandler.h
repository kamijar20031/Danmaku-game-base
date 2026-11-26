#ifndef DANMAKU_STATE_REQUEST_HANDLER_H_
#define DANMAKU_STATE_REQUEST_HANDLER_H_

#include "stateRequestObserver.h"
#include "stateTypes.h"
#include <vector>

class StateRequestHandler
{
    std::vector<IStateRequestObserver*> observers;

public:
    void subscribe(IStateRequestObserver* o)
    {
        observers.push_back(o);
    }

    void unsubscribe(IStateRequestObserver* o)
    {
        std::erase(observers, o);
    }

    void emitRequestChange(GameStateTypeCommand cmd)
    {
        for (auto* o : observers)
            o->onRequestChangeEvent(cmd);
    }

};

#endif