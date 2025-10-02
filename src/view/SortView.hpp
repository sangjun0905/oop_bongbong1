#include <string>
#include "../model/StudentList.hpp"

class SortView {
public:
    char display(); // 정렬 선택 메뉴
    void displaySortResult(StudentList& studentList);  // 정렬 결과 메뉴
private:
    int check_input(const std::string& input);
};