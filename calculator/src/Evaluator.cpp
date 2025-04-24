#include "Evaluator.hpp"

double Evaluator::evaluate(const std::string& expr) {
    Tokenizer tokenizer(expr); // Create a Tokenizer object with the input expression
    auto tokens = tokenizer.tokenize(); // Tokenize the expression
    Parser parser(tokens); // Create a Parser object with the tokens
    return parser.parseExp(); // Parse the expression and return the result
}
