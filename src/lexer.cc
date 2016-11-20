#include <iostream>

#include "lexer.hh"

using namespace std;

Lexer::Lexer(std::string input) : position(0), input(input) {}

Lexer::~Lexer() {
  for(Token *t : tokens) { delete t; }
}

void Lexer::process() {
  while(!isEnd()) {
    int before = position;

    if(input[position] > '0' && input[position] <= '9') {
      process_number();
    }

    if(isOperatorPlus())  { process_operator_plus(); }
    if(isEmptySpace())    { position++; }

    if(position == before) {
      cout << "Error" << endl;
      break;
    }
  }

  for(Token *t : tokens) {
    t->display();
  }
}

void Lexer::process_number() {
  int from = position;

  position++;

  // read in numbers
  while(!isEnd() && isNumber()) { position++; }

  // decimal places?
  if(input[position] == '.') {
    position++;

    // read all decimal values
    while(!isEnd() && isNumber()) { position++; }
  }

  std::string value = input.substr(from, position - from);
  Token::Type type  = Token::Number;

  tokens.push_back(new Token(value, type));
}

void Lexer::process_operator_plus() {
  std::string value = input.substr(position, 1);
  Token::Type type  = Token::Operator;

  tokens.push_back(new Token(value, type));

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

bool Lexer::isEmptySpace() {
  return input[position] == ' ';
}
