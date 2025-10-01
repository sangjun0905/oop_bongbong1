#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>  
#include <string>   


class Student {
private:
<<<<<<< HEAD:src/model/Student.hpp
    char name[16];
    int studentID;
    char tel[24];
    int birthYear;
    char department[64];
=======
   
    char name[17];
    char s_id[9];
    char tel[25];
    int birth;
    char department[65];
>>>>>>> origin/Modelsw:Student.h

public:
    // 생성자
    Student(const char* n, const char* id, const char* t, int b, const char* d)
        // int은 초기화 리스트에서 처리
<<<<<<< HEAD:src/model/Student.hpp
        : studentID(id), birthYear(b) 
=======
        : birth(b) 
>>>>>>> origin/Modelsw:Student.h
    {
        
        std::strncpy(name, n, 16);
        name[16] = '\0'; // 널 종료 보장

        std::strncpy(department, d, 64);
        department[64] = '\0';

        std::strncpy(s_id, id, 8);
        s_id[8] = '\0';   

<<<<<<< HEAD:src/model/Student.hpp
        std::strncpy(tel, t, 23);
        tel[23] = '\0';
=======
        std::strncpy(tel, t, 24);
        tel[24] = '\0';
>>>>>>> origin/Modelsw:Student.h
        
    }

    // Getter
    const char* getName() const { return name; } 
    int getStudentID() const { return studentID; } 
    const char* getTel() const { return tel; }
    int getBirthYear() const { return birthYear; } 
    const char* getDepartment() const { return department; }

<<<<<<< HEAD:src/model/Student.hpp
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
=======
    
    const char* get_name() const { return name; } 
   
    const char* get_s_id() const { return s_id; } 
    
    const char* get_tel() const { return tel; } 

    int get_birth() const { return birth; } 

    const char* get_department() const { return department; }

    void set_name(const char* n) {
        std::strncpy(name, n, 16);
        name[16] = '\0';
    }

 
    
    void set_s_id(const char* id){
        std::strncpy(s_id, id, 8);
        s_id[8] = '\0';  
    }

   
    void set_tel(const char* t) {
        std::strncpy(tel, t, 24);
        tel[24] = '\0';
    }

 
    void set_birth(int b) {
        birth = b;
    }

    
    void set_department(const char* d) {
        std::strncpy(department, d, 64);
        department[64] = '\0';
>>>>>>> origin/Modelsw:Student.h
    }
};

#endif