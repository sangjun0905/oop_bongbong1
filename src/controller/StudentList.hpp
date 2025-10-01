#include<vector>
#include "Student.hpp"

class Student_model{
    private:
        std::vector<Student> student_list;

    public:

        void addStudent(const Student& new_student){} //학생 추가

        const std::vector<Student>& getAllStudents(){ }//전체 리스트 반환

    };