#ifndef MAINMENUVIEW_HPP
#define MAINMENUVIEW_HPP

#include <string>

class MainMenuView {
public:
    char display();
private:
    int check_input(const std::string& input);
};

#endif