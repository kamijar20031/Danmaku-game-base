
#ifndef DANMAKU_MENUFACTORY_H_
#define DANMAKU_MENUFACTORY_H_

#include "uiMenu.h"
#include "MenuStateModel.h"
#include "MenuOption.h"
#include "MenuOptionAdapter.h"
struct MenuParts
{
    std::unique_ptr<MenuStateModel> model;
    std::unique_ptr<UIMenu> view;
};

class MenuFactory
{
public:
    static MenuParts create(std::vector<MenuOption>& options)
    {
        auto labels = MenuOptionAdapter::adapt(options);
        auto view = std::make_unique<UIMenu>(labels);
        auto model = std::make_unique<MenuStateModel>(labels.size(), *view);
        return {std::move(model), std::move(view)};
    }
};

#endif