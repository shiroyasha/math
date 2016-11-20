#pragma once

#include <string>

class Token {
  public:
    enum Type {
      Operator,
      Number,
      LeftParen,
      RightParen
    };

    Token(std::string value, Type t);

    void display();

  private:
    std::string value;
    Type type;
};
