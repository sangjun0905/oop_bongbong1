    #include "SearchSelectionView.hpp"

    #include <iostream>
    #include <string>

    namespace view::search {

    void SearchSelectionView::display() {
        
        output = "--- Search ---\n"
                "1. Search by Name\n"
                "2. Search by Student ID\n"
                "3. Search by Admission Year\n"
                "4. Search by Birth Year\n"
                "5. Search by Department\n"
                "6. List All\n"
                "> ";

        std::cout << output;
    }

    void SearchNameView::display() {
        output = "Name Keyword: ";
        std::cout << output;
    };

    void SearchStudentIDView::display() {
        output = "Student ID Keyword: ";
        std::cout << output;
    };

    void SearchAdmissionYearView::display() {
        output = "Admission Year Keyword: ";
        std::cout << output;
    };

    void SearchBirthYearView::display() {
        output = "Birth Year Keyword: ";
        std::cout << output;
    };

    void SearchDepartmentView::display() {
        output = "Department Keyword: ";
        std::cout << output;
    };

    void SearchErrorView::display() {
        output = "NO RESULTS FOUND";
        std::cout << output << std::endl;
    };

}
