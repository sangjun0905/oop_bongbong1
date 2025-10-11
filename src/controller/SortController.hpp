#include "../model/StudentList.hpp"
#include "../view/SortSelectionView.hpp"
#include "Controller.hpp"


class SortController {
private:
    SortView& sortView;
    StudentList sortedStudentList;

public:
    SortController(SortView& sortView, StudentList& studentList);
    ~SortController();

    StudentList& sortByName(StudentList& studentList);
    StudentList& sortByStudentId(StudentList& studentList);
    StudentList& sortByBirth(StudentList& studentList);
    StudentList& sortByDepartment(StudentList& studentList);
};

class SortSelectionController : public Controller {
public:
    SortSelectionController(StudentList& stuList, SortSelectionView& sortSelView);
    
    std::unique_ptr<Controller> nextController(char sel) {
        sortSelView.display();

        std::unique_ptr<Controller> cur = std::make_unique<SortByNameController>();
        return cur;
    };
};

class SortByNameController : Controller {
    SortByNameController(StudentList& stuList)

};

class SortByStudentIdController : Controller {

};

class SortByBirthController : Controller {

};

class SortByDepartmentController : Controller {

};