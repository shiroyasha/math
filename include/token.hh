#pragma once

#include <string>

class Token {
  public:
    enum Type {
      Operator,
      Number
    };

    Token(std::string value, Type t);

    void display();

  private:
    std::string value;
    Type type;
};
