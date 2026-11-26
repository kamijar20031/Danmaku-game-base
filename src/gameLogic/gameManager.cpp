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

void Game::toNewStage()
{
    // sf::RectangleShape effect;
    // effect.setSize(sf::Vector2f(APP_WIDTH, APP_HEIGHT));
    // effect.setFillColor(sf::Color(0, 0, 0, 200));
    // windowPointer->draw(effect);
    // sf::Text opt1;
    // opt1.setString("Continue to next stage");
    // opt1.setPosition(APP_WIDTH / 4.25, APP_HEIGHT / 1.3 + 10);
    // opt1.setOutlineThickness(2);
    // opt1.setFont(HUDTextures.font);
    // opt1.setFillColor(sf::Color::Yellow);
    // window.draw(opt1);
    // if (selected && unselected && !gameBoard.checkPause())
    // {
    //     SoundManager::playSound("se_ok00.wav");
    //     gameBoard.nextStage();
    //     selected = false;
    // }
}

void Game::processGameOver()
{
    // static int choice = 0;
    // sf::RectangleShape effect;
    // effect.setSize(sf::Vector2f(APP_WIDTH, APP_HEIGHT));
    // effect.setFillColor(sf::Color(0, 0, 0, 150));
    // windowPointer->draw(effect);
    // sf::Text pause;
    // pause.setString("- Game Over -");
    // pause.setOutlineThickness(2);
    // pause.setFont(HUDTextures.font);
    // pause.setPosition(APP_WIDTH / 3.67, APP_HEIGHT / 3 - 60);
    // pause.setCharacterSize(34);
    // windowPointer->draw(pause);
    // std::vector <sf::Text> opcje;
    // sf::Text opt2;
    // opt2.setString("Restart game");
    // opt2.setPosition(APP_WIDTH / 3.5, APP_HEIGHT / 3 + 10);
    // sf::Text opt3;
    // opt3.setString("Return to main menu");
    // opt3.setPosition(APP_WIDTH / 3.98, APP_HEIGHT / 3 + 60);
    // opcje.push_back(opt2);
    // opcje.push_back(opt3);
    // if (selected && unselected)
    // {
    //     SoundManager::playSound("se_ok00.wav");
    //     if (choice == 0)
    //         gameBoard.restart();
    //     else if (choice == 1)
    //     {
    //         gameBoard.restart();
    //         gameMode = 0;
    //     }
    //     selected = false;
    // }
    // if (D || S)
    // {
    //     choice++;
    //     D = false;
    //     S = false;
    //     SoundManager::playSound("se_select00.wav");
    // }
    // else if (A || W)
    // {
    //     choice--;
    //     A = false;
    //     W = false;
    //     SoundManager::playSound("se_select00.wav");
    // }
    // if (choice < 0)
    //     choice = 1;
    // else if (choice >= 2)
    //     choice = 0;
    // for (int i = 0; i < 2; i++)
    // {
    //     opcje[i].setOutlineThickness(2);
    //     opcje[i].setFont(HUDTextures.font);
    //     if (choice == i)
    //         opcje[i].setFillColor(sf::Color::Yellow);
    //     windowPointer->draw(opcje[i]);
    // }
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
    

    // if (gameMode != 0)
    // {
    //     // Actual Game
    //     mainGameProcess(dt, event);

    // }
    // else
    // {
    //     // Main Menu
    //     mainMenuProcess(dt, event);

    // }
    // if (gameBoard.isEndOfStage())
    // {
    //     // New Stage
    //     toNewStage();

    // }
    // if (gameBoard.checkPause() && ScoreManager::getLives() > 0)
    // {
    //     // Game Pause
    //     processPauseScreen();

    // }
    // if (ScoreManager::getLives() == 0)
    // {
    //     // Game Over
    //     processGameOver();

    // }
    window.clear();
    manager.process(dt);
    manager.render(window);
    window.display();
}
