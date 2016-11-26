#pragma once

#include <string>
#include <vector>

#include "token.hh"

class Lexer {
  public:
    Lexer(std::string input);
    ~Lexer();
    std::vector<Token*>* process();

  private:
    int position;
    std::string input;

    Token* process_number();

    bool isEmptySpace();
    bool isEnd();
    void next();

    bool isNumber();
    bool isOperatorPlus();
    bool isOperatorMinus();
    bool isOperatorTimes();
    bool isLeftParen();
    bool isRightParen();
};
