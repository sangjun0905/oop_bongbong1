#include "../model/StudentList.hpp"
#include "../view/SortView.hpp"



class SortController
{
private:
    SortView& sortView;
    StudentList sortedStudentList; 

public:
    SortController(SortView& sortView);
    ~SortController();

    StudentList& sortByName(StudentList& studentList);
    StudentList& sortByStudnetId(StudentList& studentList);
    StudentList& sortByBirth(StudentList& studentList);
    StudentList& sortByDepartment(StudentList& studentList);

    
};
