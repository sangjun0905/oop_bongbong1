#include <iostream>
#include "controller/MainController.hpp"

int main() {
    MainController mainController("../text.txt");
    mainController.run();
    return 0;
}
