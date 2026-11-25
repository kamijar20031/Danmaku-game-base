#include "inputHandler.h"
#include <unordered_map>

std::unordered_map<sf::Keyboard::Key, std::pair<InputEvent, InputEvent>> keyMapping = {
    {sf::Keyboard::W, {InputEvent::W_Pressed, InputEvent::W_Released}},
    {sf::Keyboard::A, {InputEvent::A_Pressed, InputEvent::A_Released}},
    {sf::Keyboard::S, {InputEvent::S_Pressed, InputEvent::S_Released}},
    {sf::Keyboard::D, {InputEvent::D_Pressed, InputEvent::D_Released}},
};

void InputHandler::process(const sf::Event& event)
{
    if (event.type == sf::Event::Closed || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
        notify(InputEvent::ESC_Pressed);

    if (event.type != sf::Event::KeyPressed && event.type != sf::Event::KeyReleased) return;

    auto keyCode = keyMapping.find(event.key.code);
    if (keyCode == keyMapping.end()) return;

    if (event.type == sf::Event::KeyPressed)
        notify(keyCode->second.first);
    else
        notify(keyCode->second.second);
}