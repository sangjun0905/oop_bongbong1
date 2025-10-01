#include<cstring>
#include<string>

class Student {
private:
   
    char name[17];
    char s_id[9];
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

        std::strncpy(s_id, id, 8);
        s_id[8] = '\0';   

        std::strncpy(tel, t, 24);
        tel[24] = '\0';
        
    }

    // Getter

    
    const char* get_name() const { return name; } 
   
    const char* get_s_id() const { return s_id; } 
    
    const char* get_tel() const { return tel; } 

    int get_birth() const { return birth; } 

    const char* get_department() const { return department; }

    void set_name(const char* n) {
        std::strncpy(name, n, 16);
        name[16] = '\0';
    }

    // s_id Setter
    
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
    }


};
