#include <iostream>

class MainMenuView {
public:
    void display() {
        std::cout << "Main menu" << std::endl;
    }
};

int main() {
    MainMenuView mainmenuview;
    mainmenuview.display();
}