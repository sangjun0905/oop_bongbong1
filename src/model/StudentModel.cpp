#include <vector>
#include "Student.h"

class StudentModel{
    private:
        std::vector<Student> studentList;

    public:

        void add_student(const Student& new_student){
            studentList.push_back(new_student);
        } //학생 추가

        const std::vector<Student>& get_all_students(){
            return studentList;
        } //전체 리스트 반환

    };