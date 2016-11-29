#include "math.hpp"

#include <iostream>
#include <vector>

int main() {
  try {
    std::vector<std::string> inputs = {
      "1.1 + 2.20 * 2",
      "(1.1 + 2.20) * 2",
      "(1.1 + (2.20)) * 2",
      "2 - 1",
      "2 * 2 * 2",
      "(-1.1 - 2.20) * -2",
      "1 / 2 - 3",
      "1 /(2 - 3)",
      "4!",
      "2 * 4!",
      "(1 + 2)! + 3",
      "(1 + 2)! * 3 + 3"
    };

    for (std::string input : inputs) {
      double result = Evaluator::evaluate(input);

      std::cout << input << " = " << result << std::endl;
    }
  } catch(std::string& e) {
    std::cout << "coungh: " << e << std::endl;
  }

  return 0;
}
