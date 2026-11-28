#ifndef DANMAKU_MENU_OPTION_STRUCT_H_
#define DANMAKU_MENU_OPTION_STRUCT_H_

#include <functional>

struct MenuOption
{
    std::string label;
    std::function<void()> cmd;
};

#endif