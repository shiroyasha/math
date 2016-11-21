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

    if(isOperatorPlus())  {
      Token *t = new Token(input.substr(position, 1), Token::OperatorPlus);
      tokens.push_back(t);

      position++;
    }

    if(isOperatorTimes())  {
      Token *t = new Token(input.substr(position, 1), Token::OperatorTimes);
      tokens.push_back(t);

      position++;
    }

    if(isLeftParen()) {
      Token *t = new Token(input.substr(position, 1), Token::LeftParen);
      tokens.push_back(t);

      position++;
    }

    if(isRightParen()) {
      Token *t = new Token(input.substr(position, 1), Token::RightParen);
      tokens.push_back(t);

      position++;
    }

    if(isEmptySpace()) { position++; }

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
