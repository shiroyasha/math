#include "math.hh"

#include <iostream>

using namespace std;

int main() {
  vector<string> inputs = {
    "1.1 + 2.20 * 2",
    "(1.1 + 2.20) * 2",
    "(1.1 + (2.20)) * 2",
    "2 - 1",
    "(-1.1 - 2.20) * -2",
    "1 / 2 - 3",
    "1 /(2 - 3)",
  };

  for(string input : inputs) {
    cout << "Parsing: '" << input << "'" << endl;

    cout << endl;

    AST* ast = Parser::parse(input);
    ast->display();
    delete ast;

    cout << endl;
  }

  return 0;
}
