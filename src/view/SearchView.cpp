#include <iostream>
#include <string>
#include <iomanip>
#include "SearchView.hpp"
#include <limits>

using namespace std;

void SearchView::display()
{
    std::cout << "--- Search ---" << std::endl;
    return;
}
char SearchView::getSearchOption()
{
    std::string input;
    
    do {
        std::cout << "1. Search by name" << std::endl;
        std::cout << "2. Search by student ID" << std::endl;
        std::cout << "3. Search by admission year" << std::endl;
        std::cout << "4. Search by birth year" << std::endl;
        std::cout << "5. Search by department name" << std::endl;
        std::cout << "6. List All" << std::endl;
        std::cout << "> ";
        
        // Clear the input buffer before using getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> input;
    } while (check_option(input));

    return input[0];
}

std::string SearchView::getSearchKeyword(char option)
{
    std::string input;
    do {
        switch (option)
        {
        case '1':
            std::cout << "Name keyword: ";
            break;
        case '2':
            std::cout << "Student ID keyword: ";
            break;
        case '3':
            std::cout << "Admission year keyword: ";
            break;
        case '4':
            std::cout << "Birth year keyword: ";
            break;
        case '5':
            std::cout << "Department name keyword: ";
            break;
        default:
            break;
        }

        // Clear the input buffer before using getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, input);
    } while(check_keyword(option, input));
    return input;
}

void SearchView::printResult(StudentList list)
{
    if (list.size() == 0)
    {
        std::cout << "NO RESULTS FOUND" << "\n\n";
        return;
    }

    cout << left << setw(15) << "Name" 
        << setw(12) << "StudentID"
        << setw(23) << "Department"
        << setw(12) << "Birth Year"
        << setw(12) << "Tel" << endl;
    
    for (int i = 0; i < 75; i++)
        cout << "-";
    
    cout << endl;

    for (int i = 0; i < list.size(); i++)
    {
        Student student = (list.getStudent(i));
        cout << left << setw(15) << student.getName() 
            << setw(12) << student.getStudentId()
            << setw(23) << student.getDepartment()
            << setw(12) << student.getBirthYear()
            << setw(12) << student.getTel() << "\n";    
    }
    cout << "\n";
}

char SearchView::check_option(std::string& input)
{
    if (input.length() == 1 && (input[0] >= '1' && input[0] <= '6')) {
        return 0; // Valid input
    }

    std::cout << "Try again!" << std::endl;
    return 1; // Invalid input
}

char SearchView::check_keyword(char option, std::string& input)
{
    // Return 1 if input is empty or exceeded maximum letters       
    switch (option)
    {
    case '1':
        if (input.empty() || input.length() > 15) {
            std::cout << "Error: Input is empty or exceeded 15 letters." << std::endl;
            return 1; // Invalid input
        }
        break;
    case '2':
        if (input.empty() || input.length() > 10) {
            std::cout << "Error: Input is empty or exceeded 10 letters." << std::endl;
            return 1; // Invalid input
        }
        break;
    case '3':
        if (input.empty() || input.length() > 4) {
            std::cout << "Error: Input is empty or exceeded 4 digits." << std::endl;
            return 1;  // Invalid input
        }
        break;
    case '4':
        if (input.empty() || input.length() > 4) {
            std::cout << "Error: Input is empty or exceeded 4 digits." << std::endl;
            return 1;  // Invalid input
        }
        break;
    case '5':
        if (input.empty() || input.length() > 23) {
            std::cout << "Error: Input is empty or exceeded 23 letters." << std::endl;
            return 1;  // Invalid input
        }
        break;
    default:
        break;
    }
    return 0; // Else: Valid input
}