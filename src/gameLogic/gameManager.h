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
    void mainMenuProcess(double dt, sf::Event& event);
    void onInputEvent(InputEvent e);
    void toNewStage();
    void processPauseScreen();
    void processGameOver();
    void process();
};