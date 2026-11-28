#ifndef DANMAKU_RENDER_MANAGER_H_
#define DANMAKU_RENDER_MANAGER_H_

#include "constants.h"
#include "uiScreen.h"
class RenderManager
{
    sf::Vector2f viewportSize = {GAME_WIDTH, GAME_HEIGHT};
    sf::Vector2f viewportOffset = {W_OFFSET, H_OFFSET};
    sf::Vector2f appSize = {APP_WIDTH, APP_HEIGHT};
    sf::Vector2f appOffset = {0, 0};
    sf::RenderWindow window;
    public:

        void render(UIScreen& screen)
        {
            screen.render(window);
        }

        void arrangeScreen(UIScreen& screen, bool inGame = false)
        {
            if (inGame)
            {
                screen.layout(viewportOffset, viewportSize);
            }
            else
            {
                screen.layout(appOffset, appSize);
            }
        }
};

#endif