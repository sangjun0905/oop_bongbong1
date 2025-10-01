#include<vector>
#include "Student.hpp"

class StudentList{
    private:
        std::vector<Student> student_list;

    public:

        void addStudent(const Student& new_student){
            student_list.push_back(new_student);
        } //학생 추가
        void addStudent(char* name, char* studentId, char* tel, char* birth, char* department) {
            Student newStudent(char* name, char* studentId, char* tel, char* birth, char* department);
            student_list.push_back(newStudent);
        }

        const std::vector<Student>& getAllStudents(){
            return student_list;
        }//전체 리스트 반환

    };