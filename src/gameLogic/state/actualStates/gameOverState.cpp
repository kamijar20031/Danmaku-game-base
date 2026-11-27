#include "gameOverState.h"

void GameOverState::onInputEvent(InputEvent e)
{
    switch (e)
    {
        case InputEvent::SPACE_Pressed:
        {
            // PRZEKAZ POTEM DO JAKIEGOS MENADZERA DZWIEKU, TAK ZEBY PO PROSTU BYL OBSERWATOREM STATEREQUESTA
            SoundManager::playSound("se_ok00.wav");
            processSelection();
            break;

        }
        case InputEvent::W_Pressed:
        case InputEvent::A_Pressed:
        {
            decrementSelection();
            SoundManager::playSound("se_select00.wav");
            break;
        }
        case InputEvent::S_Pressed:
        case InputEvent::D_Pressed:
        {
            incrementSelection();
            SoundManager::playSound("se_select00.wav");
            break;
        }
    }
}

void GameOverState::processSelection()
{
    if (selection==0)
        handler.emitRequestChange(GameStateTypeCommand::Restart);
}

void GameOverState::incrementSelection()
{
    selection++;
    // Jakas stała?
    if (selection >= 2)
        selection = 0;
}

void GameOverState::decrementSelection()
{
    selection--;
    if (selection < 0)
        selection = 2;
}

void GameOverState::update(float dt) { return; }

void GameOverState::render(sf::RenderWindow& window)
{
    sf::RectangleShape effect;
    effect.setSize(sf::Vector2f(APP_WIDTH, APP_HEIGHT));
    effect.setFillColor(sf::Color(0, 0, 0, 150));
    window.draw(effect);
    sf::Text pause;
    pause.setString("- Game Over -");
    pause.setOutlineThickness(2);
    pause.setFont(HUDTextures.font);
    pause.setPosition(APP_WIDTH / 3.67, APP_HEIGHT / 3 - 60);
    pause.setCharacterSize(34);
    window.draw(pause);
    std::vector <sf::Text> opcje;
    sf::Text opt2;
    opt2.setString("Restart game");
    opt2.setPosition(APP_WIDTH / 3.5, APP_HEIGHT / 3 + 10);
    sf::Text opt3;
    opt3.setString("Return to main menu");
    opt3.setPosition(APP_WIDTH / 3.98, APP_HEIGHT / 3 + 60);
    opcje.push_back(opt2);
    opcje.push_back(opt3);
    for (int i = 0; i < 2; i++)
    {
        opcje[i].setOutlineThickness(2);
        opcje[i].setFont(HUDTextures.font);
        if (selection == i)
            opcje[i].setFillColor(sf::Color::Yellow);
        window.draw(opcje[i]);
    }
}