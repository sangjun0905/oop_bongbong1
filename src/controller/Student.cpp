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
    Student(const char* n, const char* id, const char* t, int b, const char* d)
   
        : birth(b) 
    {
        // char 배열은 생성자 본문에서 strncpy로 처리
        std::strncpy(name, n, 16);
        name[16] = '\0'; // 널 종료 보장

        std::strncpy(department, d, 64);
        department[64] = '\0';

        std::strncpy(studnetId, id, 10);
        studnetId[10] = '\0';   

        std::strncpy(admissionYear, id, 4);
        admissionYear[4] = '\0';

        std::strncpy(tel, t, 24);
        tel[24] = '\0';
        
    }

    // Getter

    
    const char* getName() const { return name; } 
   
    const char* getStudentID() const { return studnetId; } 
    
    const char* getTel() const { return tel; } 

    int getBirthYear() const { return birth; } 

    const char* getAdmissionYear() const { return admissionYear; }

    const char* getDepartment() const { return department; }

    void setName(const char* n) {
        std::strncpy(name, n, 16);
        name[16] = '\0';
    }

    // s_id Setter
    
    void setStudentId(const char* id){
        std::strncpy(studnetId, id, 10);
        studnetId[10] = '\0';  
    }

   
    void setTel(const char* t) {
        std::strncpy(tel, t, 24);
        tel[24] = '\0';
    }


    void setBirthYear(int b) {
        birth = b;
    }

    
    void setDepartment(const char* d) {
        std::strncpy(department, d, 64);
        department[64] = '\0';
    }


};
