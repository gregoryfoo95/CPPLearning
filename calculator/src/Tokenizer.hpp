#pragma once
#include <string>
#include <vector>

enum class TokenType
{
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    LPAREN,
    RPAREN,
    END
};

struct Token {
    TokenType type; // The type of the token (e.g., number, operator, etc.)
    std::string value; // The string representation of the token
};

class Tokenizer {
    public:
        explicit Tokenizer(const std::string& expression); //use explicit to prevent implicit conversions - By marking the constructor explicit, you force every callsite to write out the conversion. That makes your intent clear and avoids accidental conversions (e.g. passing a raw int where an Inches was expected).
        std::vector<Token> tokenize(); // Tokenize the input expression and return a vector of tokens
    private:
        std::string expr;
        size_t pos; // Current position in the expression
        Token getNextToken(); // Get the next token from the expression
};