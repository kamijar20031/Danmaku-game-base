#ifndef DANMAKU_MENU_VIEW_H_
#define DANMAKU_MENU_VIEW_H_

#include "button.h"
#include "uiColumn.h"

class UIMenu : public Column
{
    std::vector<Button*> buttons;
public:
    UIMenu(std::vector<std::string> labels)
    {
        for (auto& label : labels)
        {
            auto& button = addChild<Button>(label);
            buttons.push_back(&button);
        }
            
    }

    void onSelectionChange(int selected)
    {
        for (int i = 0; i < buttons.size(); i++)
        {
            buttons[i]->changeSelection(selected==i);
        }
    }
};

#endif