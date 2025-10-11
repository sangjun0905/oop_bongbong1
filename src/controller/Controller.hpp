class Controller {
public:
    StudentList& studentList;
    View& view;

    Controller(StudentList& stuList, View& vw) : studentList(stuList), view(vw) {};

    std::unique_ptr<Controller> nextController(char sel) {
        view.display();
        return nullptr;
    }
};