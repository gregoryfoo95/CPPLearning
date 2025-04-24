#include "Parser.hpp"
#include <stdexcept> // For std::runtime_error

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens) {};

Token Parser::peek() {
    if (pos < tokens.size()) {
        return tokens[pos]; // Return the current token
    }
    return {TokenType::END, ""}; // Return end token if we reach the end of the tokens
}

Token Parser::get() {
    if (pos < tokens.size()) {
        return tokens[pos++]; // Return the current token and increment the position
    }
    return {TokenType::END, ""}; // Return end token if we reach the end of the tokens
}

double Parser::parseFactor() {
    Token token = get(); // Get the next token

    if (token.type == TokenType::NUMBER) {
        return std::stod(token.value); // Convert the number string to double and return it
    } else if (token.type == TokenType::LPAREN) {
        double result = parseExp(); // Parse the expression inside parentheses
        if (get().type != TokenType::RPAREN) {
            throw std::runtime_error("Expected closing parenthesis"); // Throw an error if no closing parenthesis is found
        }
        return result; // Return the result of the expression
    }

    throw std::runtime_error("Unexpected token: " + token.value); // Throw an error for unexpected tokens
};

double Parser::parseTerm() {
    double result = parseFactor(); // Parse the first factor

    while (true) {
        Token token = peek(); // Peek at the next token
        if (token.type == TokenType::MULTIPLY) {
            get(); // Consume the '*' token
            result *= parseFactor(); // Multiply by the next factor
        } else if (token.type == TokenType::DIVIDE) {
            get(); // Consume the '/' token
            double divisor = parseFactor(); // Parse the divisor
            if (divisor == 0) {
                throw std::runtime_error("Division by zero"); // Throw an error for division by zero
            }
            result /= divisor; // Divide by the divisor
        } else {
            break; // Exit the loop if no more '*' or '/' tokens
        }
    }

    return result; // Return the result of the term
}
double Parser::parseExp() {
    double result = parseTerm(); // Parse the first term

    while (true) {
        Token token = peek(); // Peek at the next token
        if (token.type == TokenType::PLUS) {
            get(); // Consume the '+' token
            result += parseTerm(); // Add the next term
        } else if (token.type == TokenType::MINUS) {
            get(); // Consume the '-' token
            result -= parseTerm(); // Subtract the next term
        } else {
            break; // Exit the loop if no more '+' or '-' tokens
        }
    }

    return result; // Return the final result
}
