#include "math.hh"

#include <iostream>

using namespace std;

int main() {
  AST* ast = Parser::parse("1.1 + 2.20 * 2");

  ast->display();

  delete ast;

  return 0;
}
