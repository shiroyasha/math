#pragma once

#include <vector>
#include "token.hh"

class AST {
  public:
    Token* token = NULL;

    void display();
    void display(int depth);

    void add(AST* child);

  private:
    std::vector<AST*> children;
};
