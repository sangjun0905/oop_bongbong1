#pragma once 

#include "View.hpp"

#include <string>

class MainMenuView : public View{
public:
    std::string display() override;
};
