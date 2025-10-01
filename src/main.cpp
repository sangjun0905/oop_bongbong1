#include <iostream>
#include "controller/MainController.cpp"

int main() {
    MainController mainController("student.txt");
    mainController.run();
    return 0;
}