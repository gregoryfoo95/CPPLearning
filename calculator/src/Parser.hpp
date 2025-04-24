#pragma once
#include <vector>
#include "Tokenizer.hpp" // Include the Tokenizer header file for the Token and Tokenizer classes

class Parser {
    public:
        explicit Parser(const std::vector<Token>& tokens); // Constructor that takes a vector of tokens
        double parseExp(); // Parse the tokens and return the result

    private:
        const std::vector<Token>& tokens;
        size_t pos{0}; // Current position in the tokens vector
        double parseTerm(); // Parse a term
        double parseFactor(); // Parse a factor
        Token peek();
        Token get();

};
