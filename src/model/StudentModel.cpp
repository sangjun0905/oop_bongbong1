#include <vector>
#include <stdlib.h>

#include "Student.h"

class StudentModel{
private:
    std::vector<Student> studentList;

public:
    void addStudent(const Student& new_student){
        studentList.push_back(new_student);
    } //학생 추가

    void addStudent(char* name, char* studentID, char* birthYear, char* department, char* tel) 
    {
        Student new_student(
            name,
            atoi(studentID),
            tel,
            atoi(birthYear),
            department
        ); 
        studentList.push_back(new_student);
    }

    const std::vector<Student>& getAllStudents(){
        return studentList;
    } //전체 리스트 반환
};