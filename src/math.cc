#include "math.hh"

#include <iostream>

using namespace std;

int main() {
  vector<string> inputs = {
    "1.1 + 2.20 * 2",
    "(1.1 + 2.20) * 2",
    "(1.1 + (2.20)) * 2",
    "2 - 1",
    "(-1.1 - 2.20) * -2"
  };

  for(string input : inputs) {
    AST* ast = Parser::parse(input);
    ast->display();
    delete ast;
  }

  return 0;
}
