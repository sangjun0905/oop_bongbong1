#include "../model/StudentList.hpp"
#include "../view/SortView.hpp"



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
