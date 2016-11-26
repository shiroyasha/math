#include "token.hh"

#include <iostream>

using namespace std;

Token::Token(std::string v, Token::Type t) : value(v), type(t) {}

void Token::display() {
  if(type == Number) { cout << "Number: " << value << endl; }

  if(type == OperatorPlus)   { cout << "Operator: " << value << endl; }
  if(type == OperatorMinus)  { cout << "Operator: " << value << endl; }
  if(type == OperatorTimes)  { cout << "Operator: " << value << endl; }
  if(type == OperatorDivide) { cout << "Operator: " << value << endl; }

  if(type == LeftParen)  { cout << "Token: " << value << endl; }
  if(type == RightParen) { cout << "Token: " << value << endl; }
}
