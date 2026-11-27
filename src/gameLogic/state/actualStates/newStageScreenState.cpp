#include "newStageScreenState.h"

void NextStageState::onInputEvent(InputEvent e)
{
    switch (e)
    {
        case InputEvent::SPACE_Pressed:
        {
            // PRZEKAZ POTEM DO JAKIEGOS MENADZERA DZWIEKU, TAK ZEBY PO PROSTU BYL OBSERWATOREM STATEREQUESTA
            handler.emitRequestChange(GameStateTypeCommand::Restart);
            break;

        }
    }
}


void NextStageState::update(float dt) { return; }

void NextStageState::render(sf::RenderWindow& window)
{
    sf::RectangleShape effect;
    effect.setSize(sf::Vector2f(APP_WIDTH, APP_HEIGHT));
    effect.setFillColor(sf::Color(0, 0, 0, 200));
    window.draw(effect);
    sf::Text opt1;
    opt1.setString("Continue to next stage");
    opt1.setPosition(APP_WIDTH / 4.25, APP_HEIGHT / 1.3 + 10);
    opt1.setOutlineThickness(2);
    opt1.setFont(HUDTextures.font);
    opt1.setFillColor(sf::Color::Yellow);
    window.draw(opt1);
}