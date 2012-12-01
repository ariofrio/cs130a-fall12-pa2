#ifndef AVL_H
#define AVL_H

#include "bst.h"

class avl : public bst {
public:
  virtual bool insert(int x);

private:
  bool insert_into(int x, node* &current);

  void rotate_with_left_child(node* &q);
  void rotate_with_right_child(node* &q);

  void update_height(node* p);
  int height(const node* const p) const;
};

#endif

