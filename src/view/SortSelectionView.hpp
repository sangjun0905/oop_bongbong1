#pragma once 

#include "View.hpp"

#include <string>

namespace view::sort {


class SortSelectView : public View{
public:
    void display() override;
};

class SortResultView : public View{
public:
    void display() override;
};

}