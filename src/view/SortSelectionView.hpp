#pragma once 

#include "View.hpp"

#include <string>

namespace view::sort {


class SortSelectView : public View{
public:
    std::string display() override;
};

class SortResultView : public View{
public:
    std::string display() override;
};

}