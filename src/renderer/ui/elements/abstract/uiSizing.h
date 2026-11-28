#ifndef DANMAKU_UISIZING_H_
#define DANMAKU_UISIZING_H_

#include "constants.h"

struct UIInsets
{
    float top = 0.f;
    float right = 0.f;
    float bottom = 0.f;
    float left = 0.f;
};

struct UIRect
{
    sf::Vector2f position;
    sf::Vector2f size;
};

#endif