#include <iostream>
#include "controller/MainController.cpp"

int main() {
    cout<<"good";
    MainController mainController("../text.txt");
    mainController.run();
    return 0;
}