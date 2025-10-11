class Controller {
    StudentList& studentList;
    View view;

    Controller (StudentList& stuList) : studentList(stuList) {};

    std::unique_ptr<Controller> nextController(std::unique_ptr<Controller> cur) {
        view.display();
        return cur;
    }
};