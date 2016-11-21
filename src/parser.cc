#include "parser.hh"

#include <iostream>

AST* Parser::parse(std::string input) {
  Parser p(input);

  return p._parse();
}

Parser::Parser(std::string input) : lexer(input), position(0) {}

Parser::~Parser() {}

AST* Parser::_parse() {
  tokens = lexer.process();

  AST* ast = parseExpression();

  delete tokens;

  return ast;
}

AST* Parser::parseExpression() {
  AST* leftExpr = parseTerm();

  if(isEnd()) {
    return leftExpr;
  } else if(currentType() == Token::OperatorPlus) {
    AST* op = accept();

    AST* rightExpr = parseExpression();

    op->add(leftExpr);
    op->add(rightExpr);

    return op;
  } else {
    return leftExpr;
  }
}

AST* Parser::parseTerm() {
  AST* leftFactor = parseFactor();

  if(isEnd()) {
    return leftFactor;
  } else if(currentType() == Token::OperatorTimes) {
    AST* op = accept();
    AST* rightFactor = parseTerm();

    op->add(leftFactor);
    op->add(rightFactor);

    return op;
  } else {
    return leftFactor;
  }
}

AST* Parser::parseFactor() {
  if(currentType() == Token::Number) { return accept(); }

  throw "Failed while parsing factor";
}

bool Parser::isEnd() {
  return position == tokens->size();
}

Token* Parser::current() {
  return tokens->at(position);
}

Token::Type Parser::currentType() {
  return current()->type;
}

void Parser::next() {
  position++;
}

AST* Parser::accept() {
  AST* node = new AST();
  node->token = current();

  next();

  return node;
}
