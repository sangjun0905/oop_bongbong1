#include <cstring>
#include <string>

class Student{
private:
    char name[16];
    int s_id;
    char tel[24];
    int birth;
    char department[64];

public:
    Student(const char* n, int id, const char* t, int b, const char* d) : s_id(id), birth(b){

        std::strncpy(name, n, 15);
        name[15] = '\0';

        std::strncpy(department, d, 63);
        department[63] = '\0';

        std::strncpy(tel, t, 24);
        tel[24] = '\0';

    }
    const char* getName() const { return name; }
    const int getS_id() const { return s_id; }
    const char* getTel() const { return tel; }
    const int getBirth() const { return birth; }
    const char* getDept() const { return department; }
    
    void setName(const char* n){
        std::strncpy(name, n, 15);
        name[15] = '\0';
    }
    void setS_id(int id){
        s_id = id;
    }
    void setTel(const char* t) {
        std::strncpy(tel, t, 23);
        tel[23] = '\0';
    }
    void setBirth(int b) {
        birth = b;
    }
    void setDept(const char* d) {
        std::strncpy(department, d, 63);
        department[63] = '\0';
    }
};
