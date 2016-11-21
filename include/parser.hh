#pragma once

#include <string>

#include "lexer.hh"
#include "ast.hh"


class Parser {
  public:
    static void parse(std::string input);

    Parser(std::string input);
    ~Parser();

    void _parse();

  private:
    Lexer lexer;
    int position;

    void next();
    bool isEnd();

    Token* current();
    Token::Type currentType();

    AST* parseExpression();
    /* AST* parseExpressionRest(); */

    AST* parseTerm();
    /* AST* parseTermRest(); */

    AST* parseFactor();

    AST* accept();
};
