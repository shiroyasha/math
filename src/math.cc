#include "math.hh"

#include <iostream>

using namespace std;

int main() {
  Lexer l1("1 + 2");
  l1.process();

  Lexer l2("1.1 + 2.20");
  l2.process();

  Lexer l3("1.1 + (2.20 + 2)");
  l3.process();

  return 0;
}
