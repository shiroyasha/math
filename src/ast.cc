#include "ast.hh"

#include <iostream>

using namespace std;

void AST::Node::display() {
  display(0);
}

void AST::Node::display(int depth) {
  for(int i=0; i< depth; i++) { std::cout << " "; }

  token->display();

  for(Node* n : children) { n->display(depth + 2); }
}

AST::AST() {}
AST::~AST() {}

void AST::display() {
  root->display();
}

void AST::addParent(Token* token) {
  Node* node = new Node();
  node->token = token;

  if(root != NULL) {
    root->parent = node;
    node->children.push_back(root);
  }

  root = node;
}
