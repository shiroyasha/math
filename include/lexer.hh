#pragma once

#include <string>
#include <vector>

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

class Lexer {
  public:
    Lexer(std::string input);
    void process();

  private:
    int position;
    std::string input;
    std::vector<Token*> tokens;

    void process_number();
    void process_operator_plus();

    bool isNumber();
    bool isOperatorPlus();
    bool isEmptySpace();
    bool isEnd();
};
