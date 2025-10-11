#pragma once

#include "View.hpp"
#include "../model/StudentList.hpp"

#include <string>

class SearchSelectionView : public View { 
public :
    std::string display() override;
};

class SearchNameView : public View { 
public :
    std::string display() override;
};

class SearchStudentIDView : public View { 
public :
    std::string display() override;
};

class SearchAdmissionYearView : public View { 
public :
    std::string display() override;
};

class SearchBirthYearView : public View { 
public :
    std::string display() override;
};

class SearchDepartmentView : public View { 
public :
    std::string display() override;
};

class SearchResultView : public View {
private :
    StudentList list;
public :
    SearchResultView searchResultView(StudentList& list);
    std::string display(StudentList& list);
};