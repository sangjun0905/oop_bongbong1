#pragma once
#include<vector>
#include "Student.hpp"

class StudentList{
    private:
        std::vector<Student> student_list;

    public:

        void addStudent(const Student& new_student); //학생 추가
        void addStudent(const std::string& name, const std::string& studentId, const std::string& tel, const std::string& birth, const std::string& department);

        int size();
        Student getStudent(int index);
        const std::vector<Student>& getAllStudents() const;//전체 리스트 반환

    };