#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>   // strncpy 사용을 위해 필요
#include <string>    // std::string 사용을 위해 필요


class Student {
private:
   
    char name[16];
    int s_id;
    char tel[24];
    int birth;
    char department[64];

public:
    // 생성자
    Student(const char* n, int id, const char* t, int b, const char* d)
        // int은 초기화 리스트에서 처리
        : s_id(id), birth(b) 
    {
        // char 배열은 생성자 본문에서 strncpy로 처리
        std::strncpy(name, n, 15);
        name[15] = '\0'; // 널 종료 보장

        std::strncpy(department, d, 63);
        department[63] = '\0';

        std::strncpy(tel, t, 24);
        tel[23] = '\0';
        
    }

    // Getter

    
    const char* get_name() const { return name; } 
   
    int get_s_id() const { return s_id; } 
    
    const char* get_tel() const { return tel; } 

    int get_birth() const { return birth; } 

    const char* get_department() const { return department; }

    void set_name(const char* n) {
        std::strncpy(name, n, 15);
        name[15] = '\0';
    }

    // s_id Setter
    void set_s_id(int id) {
        s_id = id;
    }

    // tel Setter: 문자열 복사 (최대 23자 + '\0')
    void set_tel(const char* t) {
        std::strncpy(tel, t, 23);
        tel[23] = '\0';
    }

    // birth Setter
    void set_birth(int b) {
        birth = b;
    }

    // department Setter: 문자열 복사 (최대 63자 + '\0')
    void set_department(const char* d) {
        std::strncpy(department, d, 63);
        department[63] = '\0';
    }
};

#endif // STUDENT_HPP