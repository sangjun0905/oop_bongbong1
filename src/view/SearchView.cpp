#include "SearchView.hpp"
#include <iostream>
#include <string>

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
        std::cout << " >";
        
        // Clear the input buffer before using getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> input;
    } while (check_option(input));

    return input[0];
}

std::string SearchView::getSearchKeyword(char option)
{
    std::string input;
    switch (option)
    {
    case '1':
        do {
        std::cout << "Name keyword: ";
        std::getline(std::cin, input);
        } while(check_keyword(option, input));
        break;
    case '2':
        do {
        std::cout << "Student ID keyword: ";
        std::getline(std::cin, input);
        } while(check_keyword(option, input));
        break;
    case '3':
        do {
        std::cout << "Admission year keyword: ";
        std::getline(std::cin, input);
        } while(check_keyword(option, input));
        break;
    case '4':
        do {
        std::cout << "Birth year keyword: ";
        std::getline(std::cin, input);
        } while(check_keyword(option, input));
        break;
    case '5':
        do {
        std::cout << "Department name keyword: ";
        std::getline(std::cin, input);
        } while(check_keyword(option, input));
        break;
    default:
        break;
    }
    return input;
}

void SearchView::printResult(StudentList list)
{
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << list.getStudent(i).getName() << std::endl;    
    }
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
    // Return 1 if the input is empty or exceeded maximum letters       
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