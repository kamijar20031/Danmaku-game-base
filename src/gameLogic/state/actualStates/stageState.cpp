#include "stageState.h"

void StageState::onInputEvent(InputEvent event)
{
    gameBoard.player->onInputEvent(event);
    if (event == InputEvent::ENTER_Pressed)
        handler.emitRequestChange(GameStateTypeCommand::Pause);
}

void StageState::update(float dt)
{
    gameBoard.gameProcess(dt, 1);

}

void StageState::render(sf::RenderWindow& window)
{
    window.draw(HUDTextures.GAMEBOARD);
    for (int i = 0; i < PointsManager::points.size(); i++)
    {
        if (!(PointsManager::points[i]->isDestroyed()))
            window.draw(PointsManager::points[i]->getSprite());
    }
    if (!(gameBoard.player->isDestroyed()))
        window.draw(gameBoard.player->getSprite());
    for (int i = 0; i < EnemyManager::enemies.size(); i++)
    {
        if (!(EnemyManager::enemies[i]->isDestroyed()))
            window.draw(EnemyManager::enemies[i]->getSprite());
    }
    for (int i = 0; i < DanmakuManager::bullets.size(); i++)
    {
        if (!(DanmakuManager::bullets[i]->isDestroyed()))
            window.draw(DanmakuManager::bullets[i]->getSprite());
    }
    window.draw(HUDTextures.HUD);
    window.draw(HUDTextures.Score);
    window.draw(HUDTextures.Power);
    window.draw(HUDTextures.Lives);
}