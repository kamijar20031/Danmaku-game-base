#ifndef DANMAKU_UISCREEN_H_
#define DANMAKU_UISCREEN_H_

#include "uiContainer.h"
#include <memory>

class UIScreen
{
private:
    std::unique_ptr<UIContainer> root;

public:
    template<typename T>
    void addChild(std::unique_ptr<T> child)
    {
        root = std::move(child);
    }
    template<typename T, typename... Args>
    T& addChild(Args&&... args)
    {
        return root->addChild<T>(std::forward<Args>(args)...);
    }
    void layout(sf::Vector2f viewportOffset, sf::Vector2f viewportSize)
    {
        auto size = root->measure();
        sf::Vector2f newOffsets = viewportOffset + (viewportSize - size)/2.0f;
        UIRect viewport{newOffsets, size};
        root->arrange(viewport);
    }
    void render(sf::RenderWindow& window)
    {
        root->render(window);
    }
};

#endif