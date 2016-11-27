#include "math.hpp"

#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> inputs = {
    "1.1 + 2.20 * 2",
    "(1.1 + 2.20) * 2",
    "(1.1 + (2.20)) * 2",
    "2 - 1",
    "(-1.1 - 2.20) * -2",
    "1 / 2 - 3",
    "1 /(2 - 3)",
  };

  for (std::string input : inputs) {
    double result = Evaluator::evaluate(input);

    std::cout << input << " = " << result << std::endl;
  }

  return 0;
}
