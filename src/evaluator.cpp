#include "evaluator.hpp"

#include <iostream>
#include <algorithm>

double Evaluator::evaluate(std::string input) {
  AST* ast = Parser::parse(input);
  ast->display();

  double result = Evaluator::evaluateAST(ast);

  delete ast;

  return result;
}

double Evaluator::evaluateAST(AST* ast) {
  switch (ast->token->type) {
    case Token::Number:
      return std::stold(ast->token->value);

    case Token::OperatorPlus:
      return plus(ast);

    case Token::OperatorMinus:
      return minus(ast);

    case Token::OperatorTimes:
      return times(ast);

    case Token::OperatorDivide:
      return divide(ast);

    default:
      throw "Unrecognized operator";
  }
}

std::vector<double> Evaluator::evaluateChildren(AST* ast) {
  std::vector<double> result;

  result.resize(ast->children.size());

  std::transform(
    ast->children.begin(),
    ast->children.end(),
    result.begin(),
    Evaluator::evaluateAST);

  return result;
}

double Evaluator::plus(AST* ast) {
  std::vector<double> children = Evaluator::evaluateChildren(ast);

  return children.at(0) + children.at(1);
}

double Evaluator::minus(AST* ast) {
  std::vector<double> children = Evaluator::evaluateChildren(ast);

  if (children.size() == 1) {
    return -children.at(0);
  } else {
    return children.at(0) - children.at(1);
  }
}

double Evaluator::times(AST* ast) {
  std::vector<double> children = Evaluator::evaluateChildren(ast);

  return children.at(0) * children.at(1);
}

double Evaluator::divide(AST* ast) {
  std::vector<double> children = Evaluator::evaluateChildren(ast);

  if (children.at(1) == 0) {
    throw "Division by zero!";
  } else {
    return children.at(0) / children.at(1);
  }
}
