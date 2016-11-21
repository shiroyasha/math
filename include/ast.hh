#pragma once

#include <vector>
#include "token.hh"

class AST {
  public:
    struct Node {
      Token* token = NULL;

      Node* parent = NULL;
      std::vector<Node*> children;

      void display();
      void display(int depth);
    };

    AST();
    ~AST();

    void addParent(Token* token);

    void display();
  private:
    Node* root = NULL;
};
