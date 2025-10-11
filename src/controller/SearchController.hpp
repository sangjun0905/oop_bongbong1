#ifndef SEARCHCONTROLLER_HPP
#define SEARCHCONTROLLER_HPP

#include "Controller.hpp"
#include "../view/SearchView.hpp"
#include <iostream>
#include <string>

class SearchController : public Controller {
    SearchView& searchView;

public:
    SearchController(StudentList& list, View& vw, SearchView& sv);

    std::unique_ptr<Controller> nextController(const std::string& input) override;
};

#endif
