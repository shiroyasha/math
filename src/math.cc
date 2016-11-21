#include "math.hh"

#include <iostream>

using namespace std;

int main() {
  AST* ast1 = Parser::parse("1.1 + 2.20 * 2");
  ast1->display();
  delete ast1;

  AST* ast2 = Parser::parse("(1.1 + 2.20) * 2");
  ast2->display();
  delete ast2;

  AST* ast3 = Parser::parse("(1.1 + (2.20)) * 2");
  ast3->display();
  delete ast3;

  return 0;
}
