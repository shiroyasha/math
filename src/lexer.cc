#include <iostream>

#include "lexer.hh"

using namespace std;

Lexer::Lexer(std::string input) : position(0), input(input) {}
Lexer::~Lexer() {}

std::vector<Token*>* Lexer::process() {
  std::vector<Token*>* tokens = new std::vector<Token*>();

  while(!isEnd()) {
    int before = position;
    Token *t = NULL;

    if(input[position] > '0' && input[position] <= '9') {
      t = process_number();
    } else if(isOperatorPlus())  {
      t = new Token(input.substr(position, 1), Token::OperatorPlus);

      next();
    } else if(isOperatorTimes())  {
      t = new Token(input.substr(position, 1), Token::OperatorTimes);

      next();
    } else if(isLeftParen()) {
      t = new Token(input.substr(position, 1), Token::LeftParen);

      next();
    } if(isRightParen()) {
      t = new Token(input.substr(position, 1), Token::RightParen);

      next();
    } else if(isEmptySpace()) {
      next();
    }

    if(t != NULL) { tokens->push_back(t); }

    if(position == before) { cout << "Error" << endl; break; }
  }

  return tokens;
}

Token* Lexer::process_number() {
  int from = position;

  next();

  // read in numbers
  while(!isEnd() && isNumber()) { next(); }

  // decimal places?
  if(input[position] == '.') {
    next();

    // read all decimal values
    while(!isEnd() && isNumber()) { next(); }
  }

  std::string value = input.substr(from, position - from);
  Token::Type type  = Token::Number;

  return new Token(value, type);
}

void Lexer::next() {
  position++;
}

bool Lexer::isEnd() {
  return position == input.size();
}

bool Lexer::isNumber() {
  return input[position] >= '0' && input[position] <= '9';
}

bool Lexer::isOperatorPlus() {
  return input[position] == '+';
}

bool Lexer::isOperatorTimes() {
  return input[position] == '*';
}

bool Lexer::isEmptySpace() {
  return input[position] == ' ';
}

bool Lexer::isLeftParen() {
  return input[position] == '(';
}

bool Lexer::isRightParen() {
  return input[position] == ')';
}
