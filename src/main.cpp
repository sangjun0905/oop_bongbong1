#include <iostream>
#include "controller/MainController.cpp"

int main() {
    MainController mainController("../text.txt");
    mainController.run();
    return 0;
}