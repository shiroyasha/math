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
    double result = Evaluator::evaluate(input);
    cout << input << " = " << result << endl;
  }

  return 0;
}
