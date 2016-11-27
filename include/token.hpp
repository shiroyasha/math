#pragma once

#include <string>

class Token {
  public:
    enum Type {
      OperatorPlus,
      OperatorMinus,
      OperatorTimes,
      OperatorDivide,
      Number,
      LeftParen,
      RightParen
    };

    Type type;

    Token(std::string value, Type t);

    void display();

    std::string value;
};
