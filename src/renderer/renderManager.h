#ifndef DANMAKU_RENDER_MANAGER_H_
#define DANMAKU_RENDER_MANAGER_H_

#include "constants.h"

class RenderManager
{
    sf::RenderWindow window;
    public:

        void render(UIScreen screen);
        
};

#endif