#pragma once

#include "lexer.hh"
#include <string>

class Parser {
  public:
    static void parse(std::string input);

    Parser(std::string input);
    ~Parser();

    void _parse();

  private:
    Lexer lexer;
    int position;

    void accept();
    void next();
    bool isEnd();

    Token* current();
    Token::Type currentType();

    void parseExpression();
    void parseExpressionRest();

    void parseTerm();
    void parseTermRest();

    void parseFactor();
};
