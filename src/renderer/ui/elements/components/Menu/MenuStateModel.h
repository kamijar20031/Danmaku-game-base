#ifndef DANMAKU_MENU_H_
#define DANMAKU_MENU_H_

#include "uiMenu.h"

class MenuStateModel
{
    int numOptions;
    int selection = 0;
    UIMenu& view;
public:
    MenuStateModel(int options, UIMenu& view) : view{view}, numOptions{options} 
    {
        view.onSelectionChange(0);
    }
    void increment()
    {
        selection++;
        if (selection >= numOptions)
            selection = 0;
        view.onSelectionChange(selection);
    }
    void decrement()
    {
        selection--;
        if (selection < 0)
            selection = numOptions - 1;
        view.onSelectionChange(selection);
    }
    int getSelection() { return selection; }
};

#endif