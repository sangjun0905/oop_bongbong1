#pragma once

#include <memory>
#include <string>

#include "../model/StudentList.hpp"

class Controller;

class MainController {
public:
    explicit MainController(const std::string& fname);

    void run();

private:
    StudentList studentList;
    std::string filename;
};

