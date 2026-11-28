#ifndef DANMAKU_MENU_OPTION_ADAPTER_H_
#define DANMAKU_MENU_OPTION_ADAPTER_H_

#include "MenuOption.h"

class MenuOptionAdapter
{
public:
    static std::vector<std::string> adapt(std::vector<MenuOption>& options)
    {
        std::vector<std::string> labels;
        for (auto& option : options)
        {
            labels.push_back(option.label);
        }
        return labels;
    }
};

#endif