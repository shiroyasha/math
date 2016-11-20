#pragma once

#include <string>
#include <vector>

#include "token.hh"

class Lexer {
  public:
    Lexer(std::string input);
    ~Lexer();
    void process();

  private:
    int position;
    std::string input;
    std::vector<Token*> tokens;

    void process_number();

    bool isEmptySpace();
    bool isEnd();

    bool isNumber();
    bool isOperatorPlus();
    bool isLeftParen();
    bool isRightParen();
};
