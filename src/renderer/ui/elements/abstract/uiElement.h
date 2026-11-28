#ifndef DANMAKU_UIELEMENT_H_
#define DANMAKU_UIELEMENT_H_

#include "uiSizing.h"
class UIElement
{
protected:
    UIRect bounds;
    UIInsets padding;
public:
    virtual ~UIElement() = default;

    virtual void render(sf::RenderWindow& window) = 0;

    virtual void setPadding(UIInsets value)
    {
        padding = value;
    }
    virtual void arrange(UIRect rect)
    {
        rect = bounds;
    }
    virtual sf::Vector2f measure() = 0;
    sf::Vector2f getPosition()
    {
        return bounds.position;
    }
    sf::Vector2f getSize()
    {
        return bounds.size;
    }
};

#endif
