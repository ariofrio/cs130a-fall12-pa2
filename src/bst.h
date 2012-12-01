#ifndef BST_H
#define BST_H

#include <cstddef>
#include "binary_tree.h"
#include "iset.h"

// implementation of binary search tree and base class for
// specialized binary search trees (AVL and splay trees)
class bst: public binary_tree, iset {
public:
  virtual bool insert(int x);
  virtual bool contains(int x);
  virtual bool erase(int x);

private:
  bool erase(node** node);

  node** find(int x);
  node** find_smallest(node** root);
};

#endif

