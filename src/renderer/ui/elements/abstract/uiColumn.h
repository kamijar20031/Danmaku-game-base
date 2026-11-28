#ifndef DANMAKU_UICOLUMN_H_
#define DANMAKU_UICOLUMN_H_

class Column : public UIContainer
{
private:
    float spacing = 10.f;

public:
    void setSpacing(float value)
    {
        spacing = value;
    }

    sf::Vector2f measure()
    {
        float width = 0.f;
        float height = 0.f;

        for (const auto& child : children)
        {
            auto childSize = child->measure();

            width = std::max(width, childSize.x);
            height += childSize.y;
        }

        if (!children.empty())
            height += spacing * (children.size() - 1);

        width += padding.left + padding.right;
        height += padding.top + padding.bottom;

        return { width, height };
    }

    virtual void arrange(UIRect area)
    {
        bounds = area;
        float availableWidth = area.size.x - padding.left - padding.right;
        float currentY = area.position.y + padding.top;

        for (auto& child : children)
        {
            auto childSize = child->measure();
            child->arrange({
                {
                    area.position.x + padding.left,
                    currentY
                },
                {
                    availableWidth,
                    childSize.y
                }
            });

            currentY += childSize.y + spacing;
        }
    }
};

#endif