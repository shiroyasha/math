#pragma once

#include <string>

class Token {
  public:
    enum Type {
      OperatorPlus,
      OperatorMinus,
      OperatorTimes,
      Number,
      LeftParen,
      RightParen
    };

    Type type;

    Token(std::string value, Type t);

    void display();

  private:
    std::string value;
};
