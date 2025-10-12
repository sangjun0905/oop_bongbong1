#pragma once

#include <memory>
#include <string>

#include "../model/StudentList.hpp"

class Controller {
public:
    StudentList& studentList;

    explicit Controller(StudentList& stuList) : studentList(stuList) {}
    virtual ~Controller() = default;
    
    virtual std::string display() = 0;

    virtual std::unique_ptr<Controller> nextController(std::string) { return nullptr; }
};
