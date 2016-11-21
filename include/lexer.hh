#pragma once

#include <string>
#include <vector>

#include "token.hh"

class Lexer {
  public:
    std::vector<Token*> tokens;

    Lexer(std::string input);
    ~Lexer();
    void process();

  private:
    int position;
    std::string input;

    void process_number();

    bool isEmptySpace();
    bool isEnd();

    bool isNumber();
    bool isOperatorPlus();
    bool isOperatorTimes();
    bool isLeftParen();
    bool isRightParen();
};
