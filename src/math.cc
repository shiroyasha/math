#include "math.hh"

#include <iostream>

using namespace std;

int main() {
  string input = "1 + 2";

  Lexer lexer(input);
  lexer.process();

  return 0;
}
