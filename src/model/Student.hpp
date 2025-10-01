#ifndef STUDENT_HPP
#define STUDENT_HPP

#include<cstring>
#include<string>

class Student {
private:
   
    char name[17];
    char studnetId[11];
    char admissionYear[5];
    char tel[25];
    int birth;
    char department[65];

public:
    // 생성자
    Student(const char* n, const char* id, const char* t, int b, const char* d);

    // Getter

    
    const char* getName() const;
   
    const char* getStudentId() const;
    
    const char* getTel() const;

    int getBirthYear() const;

    const char* getAdmissionYear() const;

    const char* getDepartment() const;

    void setName(const char* n) ;

    // s_id Setter
    
    void setStudentId(const char* id);

   
    void setTel(const char* t) ;


    void setBirthYear(int b);

    
    void setDepartment(const char* d);


};

#endif