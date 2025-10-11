#pragma once

#include <View.hpp>

#include <string>
#include <vector>

#include "../model/StudentList.hpp"

namespace view::search{

class SearchSelectionView : public View { 
public :
    void display() override;
};

class SearchNameView : public View { 
public :
    void display() override;
};

class SearchStudentIDView : public View { 
public :
    void display() override;
};

class SearchAdmissionYearView : public View { 
public :
    void display() override;
};

class SearchBirthYearView : public View { 
public :
    void display() override;
};

class SearchDepartmentView : public View { 
public :
    void display() override;
};

class SearchErrorView : public View { 
public :
    void display() override;
};


}