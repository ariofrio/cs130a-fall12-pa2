#ifndef BST_H
#define BST_H

#include "iset.h"

// implementation of binary search tree and base class for
// specialized binary search trees (AVL and splay trees)
class bst: public iset {
public:
  virtual bool insert(int x) {}
  virtual bool contains(int x) {}
  virtual bool erase(int x) {}

  class iterator {
  public:
    bool operator!=(const iterator& other) const {}
    int operator*() const {}
    const iterator* operator++() {}
  };

  // print space-separated pre-order, then in-order traversals
  void print() {}

private:
  virtual iterator preorder_begin() {}
  virtual iterator preorder_end() {}
  virtual iterator inorder_begin() {}
  virtual iterator inorder_end() {}
};

#endif


