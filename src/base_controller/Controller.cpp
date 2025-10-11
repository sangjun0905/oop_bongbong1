#include "../model/StudentList.hpp"
#include "../view/View.hpp"


class Controller {
public:
    StudentList& studentList;
    View& view;

    Controller(StudentList& stuList, View& vw) : studentList(stuList), view(vw) {};
    
    void display() {
        view.display();
    }

    std::unique_ptr<Controller> nextController(std::string input) {
        return nullptr;
    }
};