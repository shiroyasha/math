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

  parseExpression();

  ast.display();
}

void Parser::parseExpression() {
  std::cout << "expr" << std::endl;
  parseTerm();
  parseExpressionRest();
}

void Parser::parseExpressionRest() {
  std::cout << "expr'" << std::endl;
  if(isEnd()) { return; }

  if(currentType() == Token::OperatorPlus) {
    accept();
    parseExpression();
  }
}

void Parser::parseTerm() {
  std::cout << "term" << std::endl;
  parseFactor();
  parseTermRest();
}

void Parser::parseTermRest() {
  std::cout << "term'" << std::endl;
  if(isEnd()) { return; }

  if(currentType() == Token::OperatorTimes) {
    accept();
    parseTerm();
  }
}

void Parser::parseFactor() {
  std::cout << "factor" << std::endl;
  if(currentType() == Token::Number) {
    accept();
  }
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

void Parser::accept() {
  std::cout << "Accepted" << std::endl;
  current()->display();

  ast.addParent(current());

  next();
}
