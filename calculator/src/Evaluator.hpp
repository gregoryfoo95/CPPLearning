#pragma once
#include <vector>
#include "Tokenizer.hpp"
#include "Parser.hpp"

//Evaluator class here simply exists to expose the evaluate method for me, hence static allows me to use that method without instantiating that class
class Evaluator {
    public:
        static double evaluate(const std::string& expr);
};

