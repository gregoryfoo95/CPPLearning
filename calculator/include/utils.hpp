#pragma once      // Header guard that tells the compiler to only include this header file once per compilation unit
#include <string> //Include the string library for using std::string

inline void trim(std::string &str)
{                                                        // inline to allow header-only implementation and reduce call overhead
    size_t start = str.find_first_not_of(" \t\n\r\f\v"); // Find the first non-whitespace character
    size_t end = str.find_last_not_of(" \t\n\r\f\v");    // Find the last non-whitespace character

    if (start == std::string::npos || end == std::string::npos)
    {                // If no non-whitespace characters are found
        str.clear(); // Clear the string
    }
    else
    {
        str = str.substr(start, end - start + 1); // Extract the substring from start to end
    }
}