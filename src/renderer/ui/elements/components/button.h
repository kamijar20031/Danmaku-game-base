#ifndef DANMAKU_BUTTON_H_
#define DANMAKU_BUTTON_H_

#include "uiElement.h"
#include "hud.h"

extern HUDManager HUDTextures;
class Button : public UIElement
{
    sf::Text label;
    bool selected = false;
public:
    Button(std::string text);
    void changeSelection(bool s) { selected=s; }
    void render(sf::RenderWindow& window);
    void arrange(UIRect area);
    sf::Vector2f measure();
};

#endif