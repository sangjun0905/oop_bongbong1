#pragma once 

#include "View.hpp"

#include <string>

class InsertionNameView : public View{
public:
    std::string display() override;
};

class InsertionStudentIDView : public View{
public:
    std::string display() override;
};

class InsertionBirthYearView : public View{
public:
    std::string display() override;
};

class InsertionDepartmentView : public View{
public:
    std::string display() override;
};

class InsertionTelView : public View{
public:
    std::string display() override;
};
