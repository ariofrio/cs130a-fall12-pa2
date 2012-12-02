#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cstddef>

class binary_tree {
public:
  binary_tree() : root(NULL) {}

  // print space-separated pre-order, then in-order traversals
  void print() const;
  static bool verbose;

protected:
  struct node {
    int value;
    int data;

    node* left;
    node* right;

    node(int value) : value(value), left(NULL), right(NULL) {}
    node(int value, int data) : 
      value(value), data(data), left(NULL), right(NULL) {}
  };

  node* root;

private:
  static void print_preorder(const node* const root);
  static void print_inorder(const node* const root);
  static void print_unique(const node* const root);
};

#endif

