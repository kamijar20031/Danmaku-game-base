#include "pauseState.h"

PauseState::PauseState(StateRequestHandler& handler) : IGameState(handler) 
{
    options = {
        {
            "Return to game",
            [&handler]()
            {
                handler.emitRequestChange(GameStateTypeCommand::Unpause);
            }
        },
        {
            "Restart",
            [&handler]()
            {
                handler.emitRequestChange(GameStateTypeCommand::Restart);
            }
        },
        {
            "Return to main menu",
            [this]()
            {
            }
        }
    };
    MenuParts viewmodel = MenuFactory::create(options);
    menuModel = std::move(viewmodel.model);
    screen.addChild<UIMenu>(std::move(viewmodel.view));
    RenderManager pierdolsie;
    pierdolsie.arrangeScreen(screen, true);
}

void PauseState::onInputEvent(InputEvent event)
{
    switch (event)
    {
        case InputEvent::ENTER_Pressed:
        {
            // PRZEKAZ POTEM DO JAKIEGOS MENADZERA DZWIEKU, TAK ZEBY PO PROSTU BYL OBSERWATOREM STATEREQUESTA
            SoundManager::playSound("se_cancel00.wav");
            handler.emitRequestChange(GameStateTypeCommand::Unpause);
            break;
        }
        case InputEvent::SPACE_Pressed:
        {
            // PRZEKAZ POTEM DO JAKIEGOS MENADZERA DZWIEKU, TAK ZEBY PO PROSTU BYL OBSERWATOREM STATEREQUESTA
            SoundManager::playSound("se_ok00.wav");
            processPauseSelection();
            break;

        }
        case InputEvent::W_Pressed:
        case InputEvent::A_Pressed:
        {
            menuModel->decrement();
            SoundManager::playSound("se_select00.wav");
            break;
        }
        case InputEvent::S_Pressed:
        case InputEvent::D_Pressed:
        {
            menuModel->increment();
            SoundManager::playSound("se_select00.wav");
            break;
        }
    }
}


void PauseState::processPauseSelection()
{
    options[menuModel->getSelection()].cmd();
}

void PauseState::update(float dt)
{
    return;
}

void PauseState::render(sf::RenderWindow& window)
{
    screen.render(window);
}