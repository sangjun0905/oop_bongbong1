#pragma once 

#include "View.hpp"

#include <string>

namespace view::insertion {

class InsertionNameView : public View{
public:
    void display() override;
};

class InsertionStudentIDView : public View{
public:
    void display() override;
};

class InsertionBirthYearView : public View{
public:
    void display() override;
};

class InsertionDepartmentView : public View{
public:
    void display() override;
};

class InsertionTelView : public View{
public:
    void display() override;
};

};