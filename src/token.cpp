#include "token.hpp"

#include <iostream>

Token::Token(std::string v, Token::Type t) : value(v), type(t) {}

void Token::display() {
  switch (type) {
    case Number:
      std::cout << "Number: " << value;
      break;

    case OperatorPlus:
    case OperatorMinus:
    case OperatorTimes:
    case OperatorDivide:
      std::cout << "Operator: " << value;
      break;

    case LeftParen:
    case RightParen:
      std::cout << "Token: " << value;
      break;
  }

  std::cout << std::endl;
}
