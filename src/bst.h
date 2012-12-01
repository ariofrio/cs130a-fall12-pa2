#ifndef BST_H
#define BST_H

#include "binary_tree.h"

class bst: public binary_tree {
public:
  virtual ~bst() {}
  virtual bool insert(int x) = 0;
  virtual bool contains(int x) = 0;
  virtual bool erase(int x) = 0;
};

#endif

