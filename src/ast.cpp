#include "ast.hpp"

#include <iostream>

void AST::display() {
  display(0);
}

void AST::display(int depth) {
  for (int i=0; i< depth; i++) { std::cout << " "; }

  token->display();

  for (AST* n : children) {
    if (n == NULL) {
      for (int i=0; i< depth + 2; i++) { std::cout << " "; }
      std::cout << "NULL" << std::endl;
    } else {
      n->display(depth + 2);
    }
  }
}

void AST::add(AST* child) {
  children.push_back(child);
}
