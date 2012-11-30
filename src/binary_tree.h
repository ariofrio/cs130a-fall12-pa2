#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cstddef>
#include <iostream>

class binary_tree {
public:
  binary_tree() : root(NULL) {}

  // print space-separated pre-order, then in-order traversals
  void print() const;

protected:
  struct node {
    int value;
    node* left;
    node* right;

    node(int value) : value(value), left(NULL), right(NULL) {}
  };

  node* root;
private:
  void print_preorder(const node* const root) const;
  void print_inorder(const node* const root) const;
};

#endif

