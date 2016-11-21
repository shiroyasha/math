#pragma once

#include <string>

#include "lexer.hh"
#include "ast.hh"


class Parser {
  public:
    static AST* parse(std::string input);

    Parser(std::string input);
    ~Parser();

    AST* _parse();
  private:
    Lexer lexer;
    std::vector<Token*>* tokens = NULL;

    int position;

    void next();
    bool isEnd();

    Token* current();
    Token::Type currentType();

    AST* parseExpression();
    AST* parseTerm();
    AST* parseFactor();

    void expect(Token::Type type);
    AST* accept();
};
