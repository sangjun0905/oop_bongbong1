#include<cstring>
#include<string>

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
        const char* get_name() const { return name; }
        const int get_s_id() const { return s_id; }
        const char* get_tel() const { return tel; }
        const int get_birth() const { return birth; }
        const char* get_dept() const { return department; }
        
        void set_name(const char* n){
            std::strncpy(name,n, 15);
            name[15] = '\0';
        }

        void set_s_id(int id){
            s_id = id;
        }

        void set_tel(const char* t) {
            std::strncpy(tel, t, 23);
            tel[23] = '\0';
        }

        void set_birth(int b) {
            birth = b;
        }

        void set_dept(const char* d) {
            std::strncpy(department, d, 63);
            department[63] = '\0';
        }

};
