#include "parser.hh"

#include <iostream>

void Parser::parse(std::string input) {
  Parser p(input);
  p._parse();
}

Parser::Parser(std::string input) : lexer(input), position(0) {}

Parser::~Parser() {}

void Parser::_parse() {
  lexer.process();

  std::cout << std::endl << "Parsing started" << std::endl;

  AST* ast = parseExpression();

  std::cout << std::endl << "Parsing ended" << std::endl;

  ast->display();
}

AST* Parser::parseExpression() {
  std::cout << "expr" << std::endl;

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
  std::cout << "term" << std::endl;

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
  return position == lexer.tokens.size();
}

Token* Parser::current() {
  return lexer.tokens.at(position);
}

Token::Type Parser::currentType() {
  return current()->type;
}

void Parser::next() {
  position++;
}

AST* Parser::accept() {
  std::cout << "Accepted" << std::endl;
  current()->display();

  AST* node = new AST();
  node->token = current();

  next();

  return node;
}
