#pragma once

#include "View.hpp"
#include <iostream>
#include <string>

class FileView : public View {
    std::string typeoferror;
public:
    std::string display() override {
        std::cout << output << std::endl;
        return output;
    };
    void setError(std::string error) {
        typeoferror = error;
    }
};