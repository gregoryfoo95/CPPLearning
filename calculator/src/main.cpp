#include <iostream>
#include "utils.hpp" //Include the utils header file for utility functions

int main()
{
    std::cout << "Welcome to CLI Calculator!" << std::endl;
    std::cout << "Enter an expression: ";
    std::string line;
    std::getline(std::cin, line); // The std::getline function in C++ reads an entire line of text from an input stream, including whitespace characters, and stores it in a string. It's defined in the <string> header. The function extracts characters from the input stream until it encounters a delimiter, which is a newline character \n by default, or the end-of-file. The delimiter character is extracted but not appended to the string.

    std::cout << "You entered: " << line << std::endl;
    trim(line);                                          // Call the trim function to remove leading and trailing whitespace from the input line
    std::cout << "Trimmed input: " << line << std::endl; // Output the trimmed input

    return 0;
}