#include <cstring>
#include <string>

class Student{
private:
    char name[16];
    int studentID;
    char tel[24];
    int birthYear;
    char department[64];

public:
    Student(const char* n, int id, const char* t, int b, const char* d) : studentID(id), birthYear(b){
        std::strncpy(name, n, 15);
        name[15] = '\0';

        std::strncpy(department, d, 63);
        department[63] = '\0';

        std::strncpy(tel, t, 24);
        tel[24] = '\0';
    }
    const char* getName() const { return name; }
    const int getStudentID() const { return studentID; }
    const char* getTel() const { return tel; }
    const int getBirthYear() const { return birthYear; }
    const char* getDept() const { return department; }
    
    void setName(const char* n){
        std::strncpy(name, n, 15);
        name[15] = '\0';
    }
    void setStudentID(int id){
        studentID = id;
    }
    void setTel(const char* t) {
        std::strncpy(tel, t, 23);
        tel[23] = '\0';
    }
    void setBirthYear(int b) {
        birthYear = b;
    }
    void setDept(const char* d) {
        std::strncpy(department, d, 63);
        department[63] = '\0';
    }
};
