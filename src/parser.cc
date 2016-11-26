#include "parser.hh"

#include <iostream>

using namespace std;

AST* Parser::parse(std::string input) {
  Parser p(input);

  return p._parse();
}

Parser::Parser(std::string input) : lexer(input), position(0) {}

Parser::~Parser() {
  if(tokens != NULL) { delete tokens; }
}

AST* Parser::_parse() {
  tokens = lexer.process();

  return parseExpression();
}

AST* Parser::parseExpression() {
  AST* leftExpr = parseTerm();

  if(isEnd()) {
    return leftExpr;
  } else if(currentType() == Token::OperatorPlus || currentType() == Token::OperatorMinus) {
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

  if(currentType() == Token::LeftParen) {
    next();

    AST* expr = parseExpression();

    expect(Token::RightParen);

    return expr;
  }

  if(currentType() == Token::OperatorMinus) {
    AST* unaryMinus = accept();

    if(currentType() == Token::Number) {
      AST* value = accept();

      unaryMinus->add(value);
    } else {
      throw "Expected number";
    }

    return unaryMinus;
  }

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

void Parser::expect(Token::Type type) {
  if(currentType() == type) {
    next();
  } else {
    std::cout << "Expected different type" << std::endl;
    throw "Expected different type";
  }
}
