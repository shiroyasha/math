#pragma once

#include <vector>
#include "token.hpp"

class AST {
  public:
    Token* token = NULL;
    std::vector<AST*> children;

    void display();
    void display(int depth);

    void add(AST* child);
};
