#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>   // strncpy 사용을 위해 필요
#include <string>    // std::string 사용을 위해 필요


class Student {
private:
    char name[16];
    int studentID;
    char tel[24];
    int birthYear;
    char department[64];

public:
    // 생성자
    Student(const char* n, int id, const char* t, int b, const char* d)
        // int은 초기화 리스트에서 처리
        : studentID(id), birthYear(b) 
    {
        // char 배열은 생성자 본문에서 strncpy로 처리
        std::strncpy(name, n, 15);
        name[15] = '\0'; // 널 종료 보장

        std::strncpy(department, d, 63);
        department[63] = '\0';

        std::strncpy(tel, t, 23);
        tel[23] = '\0';
        
    }

    // Getter
    const char* getName() const { return name; } 
    int getStudentID() const { return studentID; } 
    const char* getTel() const { return tel; }
    int getBirthYear() const { return birthYear; } 
    const char* getDepartment() const { return department; }

    void setName(const char* n) {
        std::strncpy(name, n, 15);
        name[15] = '\0';
    }
    // s_id Setter
    void setStudentID(int id) {
        studentID = id;
    }
    // tel Setter: 문자열 복사 (최대 23자 + '\0')
    void setTel(const char* t) {
        std::strncpy(tel, t, 23);
        tel[23] = '\0';
    }
    // birth Setter
    void setBirthYear(int b) {
        birthYear = b;
    }
    // department Setter: 문자열 복사 (최대 63자 + '\0')
    void setDepartment(const char* d) {
        std::strncpy(department, d, 63);
        department[63] = '\0';
    }
};

#endif // STUDENT_HPP