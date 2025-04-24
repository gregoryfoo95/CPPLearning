#include "Tokenizer.hpp"
#include <cctype> // For std::isdigit

//Implement constructor
// Why use an initializer list?
// Efficiency: avoids constructing expr once and then copying/assigning to it.
// Necessity: for members that are references, const types, or types without a default constructor, you must initialize them this way.
Tokenizer::Tokenizer(const std::string& expression) : expr(expression) {}


//Implement tokenize()
std::vector<Token> Tokenizer::tokenize() {
    std::vector<Token> tokens; // Vector to store the tokens
    Token token;

    do {
        token = getNextToken(); // Get the next token
        tokens.push_back(token); // Add the token to the vector
    } while (token.type != TokenType::END); // Continue until we reach the end token

    return tokens; // Return the vector of tokens
}

Token Tokenizer::getNextToken() {
    while (pos < expr.size() && std::isspace(expr[pos])) {
        ++pos; // Skip whitespace
    }

    if (pos >= expr.size()) {
        return {TokenType::END, ""}; // Return end token if we reach the end of the expression
    }

    char currentChar = expr[pos];

    if (std::isdigit(currentChar)) {
        size_t start = pos;
        while (pos < expr.size() && std::isdigit(expr[pos])) {
            ++pos; // Read the number
        }
        return {TokenType::NUMBER, expr.substr(start, pos - start)}; // Return number token
    }

    // Handle operators and parentheses
    switch (currentChar) {
        case '+':
            ++pos;
            return {TokenType::PLUS, "+"};
        case '-':
            ++pos;
            return {TokenType::MINUS, "-"};
        case '*':
            ++pos;
            return {TokenType::MULTIPLY, "*"};
        case '/':
            ++pos;
            return {TokenType::DIVIDE, "/"};
        case '(':
            ++pos;
            return {TokenType::LPAREN, "("};
        case ')':
            ++pos;
            return {TokenType::RPAREN, ")"};
        default:
            return {TokenType::END, ""}; // Return end token for unrecognized characters
    }
}
//Implement getNextToken()