#pragma once

#include <vector>
#include <string>

#include "token.hh"
#include "ast.hh"
#include "parser.hh"

class Evaluator {
  public:
    static double evaluate(std::string input);

    static double evaluateAST(AST* ast);
    static std::vector<double> evaluateChildren(AST* ast);

    static double plus(AST* ast);
    static double minus(AST* ast);
    static double times(AST* ast);
    static double divide(AST* ast);
};
