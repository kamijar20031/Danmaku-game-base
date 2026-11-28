#include "button.h"

Button::Button(std::string text)
{
    label.setString(text);
    label.setOutlineThickness(2);
    label.setFont(HUDTextures.font);
}

void Button::render(sf::RenderWindow& window)
{
    if (selected)
        label.setFillColor(sf::Color::Yellow);
    else
        label.setFillColor(sf::Color::White);
    window.draw(label);
}

void Button::arrange(UIRect area)
{
    bounds = area;
    sf::FloatRect textBounds = label.getLocalBounds();

    label.setOrigin(
        textBounds.left + textBounds.width / 2.f,
        textBounds.top + textBounds.height / 2.f
    );

    label.setPosition(
        area.position.x + area.size.x / 2.f,
        area.position.y + area.size.y / 2.f
    );
}

sf::Vector2f Button::measure()
{
    sf::FloatRect bounds = label.getLocalBounds();
    float width = padding.left + padding.right + bounds.width;
    float height = padding.top + padding.bottom + bounds.height;
    return {width, height};
}