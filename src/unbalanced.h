#ifndef UNBALANCED_H
#define UNBALANCED_H

#include "bst.h"

class unbalanced: public bst {
public:
  virtual ~unbalanced() {}
  virtual bool insert(int x);
  virtual bool contains(int x);
  virtual bool erase(int x);

  static bool insert(int x, node* &p);
  static bool contains(int x, node* &p);
  static bool erase(int x, node* &p);
  static void erase_node(node* &p);
  static node* &find_smallest(node* &p);
};

#endif


