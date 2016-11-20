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
    void process_operator_plus();

    bool isNumber();
    bool isOperatorPlus();
    bool isEmptySpace();
    bool isEnd();
};
