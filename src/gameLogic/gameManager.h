#pragma once
#include "constants.h"
#include "board.h"
class Game
{
	int gameMode;
	sf::RenderWindow* windowPointer;
    InputHandler handler;
	Board gameBoard;
    bool selected;
    bool unselected;
    int selection;
    bool pressedPause;
    bool releasedPause;
    bool stop;

    sf::Clock clock;
    sf::Time time;
public:
    Game(sf::RenderWindow* window);
    void processBasicEvents(const sf::Event& event);
    void processInGameEvents(const sf::Event& event);
    void drawGame();
    void mainGameProcess(double dt, sf::Event& event);
    void mainMenuProcess(double dt, sf::Event& event);
    void toNewStage();
    void processPauseScreen();
    void processGameOver();
    void process();
};