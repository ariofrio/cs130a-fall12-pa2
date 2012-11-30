#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cstddef>

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
  void print_preorder(node* root) const;
  void print_inorder(node* root) const;
};

#endif

