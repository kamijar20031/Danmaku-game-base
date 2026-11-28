#ifndef DANMAKU_UIROW_H_
#define DANMAKU_UIROW_H_

class Row : public UIContainer
{
private:
    float spacing = 10.f;
    UIInsets padding;

public:
    void setSpacing(float value)
    {
        spacing = value;
    }

    void setPadding(UIInsets value)
    {
        padding = value;
    }

    sf::Vector2f measure()
    {
        float width = 0.f;
        float height = 0.f;

        for (const auto& child : children)
        {
            auto childSize = child->measure();

            height = std::max(height, childSize.y);
            width += childSize.x;
        }

        if (!children.empty())
            width += spacing * (children.size() - 1);

        width += padding.left + padding.right;
        height += padding.top + padding.bottom;

        return { width, height };
    }

    void arrange(UIRect area)
    {
        bounds = area;

        float availableHeight = area.size.y - padding.top - padding.bottom;

        float currentX = area.position.x + padding.left;

        for (auto& child : children)
        {
            auto childSize = child->measure();

            child->arrange({
                {
                    currentX,
                    area.position.y + padding.top
                },
                {
                    childSize.x
                    availableHeight
                }
            });

            currentX += childSize.x + spacing;
        }
    }
};

#endif