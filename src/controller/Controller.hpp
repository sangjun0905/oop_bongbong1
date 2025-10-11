#pragma once

#include <memory>
#include <string>

#include "../model/StudentList.hpp"
#include "../view/View.hpp"

class Controller {
public:
    StudentList& studentList;
    View& view;

    Controller(StudentList& stuList, View& vw) : studentList(stuList), view(vw) {}
    virtual ~Controller() = default;
    
    virtual std::string display() {
        return view.display();
    }

    virtual std::unique_ptr<Controller> nextController(std::string) { return nullptr; }
};
