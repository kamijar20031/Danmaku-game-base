#ifndef DANMAKU_STATE_REQUEST_COMMANDS_H_
#define DANMAKU_STATE_REQUEST_COMMANDS_H_

enum class GameStateTypeCommand
{
    StartMainMenu,
    StartStage,
    Pause,
    Unpause,
    GameOver,
    Restart
};

enum class GameStateType
{
    MainMenu,
    Stage,
    Paused,
    GameOver
};

#endif