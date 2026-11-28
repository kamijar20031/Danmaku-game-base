#ifndef DANMAKU_UICONTAINER_H_
#define DANMAKU_UICONTAINER_H_

#include <memory>
#include "uiElement.h"

class UIContainer : public UIElement
{
protected:
    std::vector<std::unique_ptr<UIElement>> children;
    
public:
    template<typename T, typename... Args>
    T& addChild(Args&&... args)
    {
        auto child = std::make_unique<T>(std::forward<Args>(args)...);
        T& reference = *child;
        children.push_back(std::move(child));
        return reference;
    }

    void render(sf::RenderWindow& window)
    {
        for (auto& child : children)
        {
            child->render(window);
        }
    }
};

#endif