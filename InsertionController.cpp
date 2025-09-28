#include <iostream>
#include <string.h>

class InsertionController
{
private:
    //StudentInfoModel* studim;
    //InsetionView* insView;
    char name_in[16];
    char studID_in[10];
    char birthYear_in[4];
    char dept_in[64];
    char tel_in[24];

public:
    InsertionController(/* args */);
    ~InsertionController();
    void insert();
};

InsertionController::InsertionController(/* InsetionView* insetionViewp, Student_model* studentModelp */)
{
    // studim = studentModelp;
    // insView = insertionViewp;
}

InsertionController::~InsertionController()
{
}

void InsertionController::insert()
{
    // strcpy(name_in, insView.getName());
    // strcpy(studID_in, insView.getStudentID());
    // strcpy(birthYear_in, insView.getBirthYear());
    // strcpy(dept_in, insView.getDepartment());
    // strcpy(tel_in, insView.getTel());
    // Student* newStudent = new Student(
    // name_in, studID_in, birthYear_in, dept_in, tel_in);
    // studim->add_student(newStudent);
}