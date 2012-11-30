#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cstddef>
#include <iostream>

class binary_tree {
public:
  // print space-separated pre-order, then in-order traversals
  void print() const;

protected:
  struct node {
    int value;
    node* left = NULL;
    node* right = NULL;

    node(int value) : value(value) {}
  };

  node* root = NULL;
private:
  void print_preorder(const node* const root) const;
  void print_inorder(const node* const root) const;
};

#endif

