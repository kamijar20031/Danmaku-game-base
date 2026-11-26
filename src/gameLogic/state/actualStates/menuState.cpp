#include "menuState.h"
void MenuState::onInputEvent(InputEvent event)
{
    switch (event)
    {
        case InputEvent::SPACE_Pressed:
        {
            // PRZEKAZ POTEM DO JAKIEGOS MENADZERA DZWIEKU, TAK ZEBY PO PROSTU BYL OBSERWATOREM STATEREQUESTA
            SoundManager::playSound("se_ok00.wav");
            processMenuSelection();
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
        default: break;
    }
}

void MenuState::incrementSelection()
{
    selection++;
    // Jakas stała?
    if (selection >= HUDTextures.Options.size())
        selection = 0;
}

void MenuState::decrementSelection()
{
    selection--;
    if (selection < 0)
        selection = HUDTextures.Options.size() - 1;
}

void MenuState::processMenuSelection()
{
    if (selection==0)
        handler.emitRequestChange(GameStateTypeCommand::StartStage);
}

void MenuState::update(float dt)
{
    return;
}

void MenuState::render(sf::RenderWindow& window)
{

    window.draw(HUDTextures.MainMenu);
    for (int i = 0; i < HUDTextures.Options.size(); i++)
    {
        if (i == selection)
            HUDTextures.Options[i].setOutlineColor(sf::Color::Red);
        else
            HUDTextures.Options[i].setOutlineColor(sf::Color::Black);
        window.draw(HUDTextures.Options[i]);
    }
}