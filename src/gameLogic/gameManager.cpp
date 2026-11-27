#include "gameManager.h"
Game::Game(sf::RenderWindow& window) : window{window}, handler{}, requestHandler{}, manager{handler, requestHandler}
{
    requestHandler.emitRequestChange(GameStateTypeCommand::StartMainMenu);
    handler.subscribe(this);
}
Game::~Game()
{
    handler.unsubscribe(this);
}

void Game::onInputEvent(InputEvent e)
{
    if (e==InputEvent::ESC_Pressed)
        window.close();
}

void Game::process()
{
    sf::Event event;
    
    time = clock.restart();
    float dt = time.asSeconds();

    while (window.pollEvent(event))
    {
        handler.process(event);
    }
    
    window.clear();
    manager.process(dt);
    manager.render(window);
    window.display();
}
