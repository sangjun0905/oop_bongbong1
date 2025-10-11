#pragma once

#include <View.hpp>
#include "../model/StudentList.hpp"

#include <string>
#include <vector>

namespace view::search{

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

class SearchErrorView : public View { 
public :
    std::string display() override;
};

class SearchResultView : public View {
public:
    std::string display(StudentList List);
};

}