#pragma once 

#include "View.hpp"

#include <string>

namespace view::mainmenu {

class MainMenuView :public View{
public:
    std::string display() override;
};

class MainMenuErrorView : public View{
    public:
    std::string display() override;
};

}