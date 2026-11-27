#pragma once
#include "constants.h"
#include "board.h"
#include "stateManager.h"
class Game : IInputObserver
{
	sf::RenderWindow& window;
    InputHandler handler;
    StateRequestHandler requestHandler;
    GameStateManager manager;
    sf::Clock clock;
    sf::Time time;
public:
    Game(sf::RenderWindow& window);
    ~Game();
    void onInputEvent(InputEvent e);
    void process();
};