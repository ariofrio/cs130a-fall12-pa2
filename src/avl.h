#ifndef AVL_H
#define AVL_H

#include "bst.h"

class avl : public bst {
public:
  virtual ~avl() {}
  virtual bool insert(int x);
  virtual bool contains(int x);
  virtual bool erase(int x);

  static bool insert(int x, node* &p);
  static bool contains(int x, node* &p);
  static bool erase(int x, node* &p);
  static void erase_node(node* &p);
  static void replace_with_successor(node* &p);
  static void replace_with_successor(node* &p, node* &s);

  static void ensure_balanced(node* &q);
  static void rotate_with_left_child(node* &q);
  static void rotate_with_right_child(node* &q);

  static void update_height(node* const p);
  static int height(const node* const p);
};

#endif

