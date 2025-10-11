#include <string>
#include <iostream>

class View {
    std::string output;

    View() {
        output = "";
    }

    std::string display() {
        std::cout << output << std::endl;
        return output;
    }
}