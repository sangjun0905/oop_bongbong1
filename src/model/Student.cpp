#include "Student.hpp"
#include <cstring>

// Constructor
Student::Student(const char* n, const char* id, const char* t, int b, const char* d)
    : birth(b) 
{
    std::strncpy(name, n, 16);
    name[16] = '\0';

    std::strncpy(department, d, 64);
    department[64] = '\0';

    std::strncpy(studnetId, id, 10);
    studnetId[10] = '\0';   

    std::strncpy(admissionYear, id, 4);
    admissionYear[4] = '\0';

    std::strncpy(tel, t, 24);
    tel[24] = '\0';
}

// Getters
const char* Student::getName() const { return name; } 
const char* Student::getStudentId() const { return studnetId; } 
const char* Student::getTel() const { return tel; } 
int Student::getBirthYear() const { return birth; } 
const char* Student::getAdmissionYear() const { return admissionYear; }
const char* Student::getDepartment() const { return department; }

// Setters
void Student::setName(const char* n) {
    std::strncpy(name, n, 16);
    name[16] = '\0';
}

void Student::setStudentId(const char* id){
    std::strncpy(studnetId, id, 10);
    studnetId[10] = '\0';  
}

void Student::setTel(const char* t) {
    std::strncpy(tel, t, 24);
    tel[24] = '\0';
}

void Student::setBirthYear(int b) {
    birth = b;
}

void Student::setDepartment(const char* d) {
    std::strncpy(department, d, 64);
    department[64] = '\0';
}