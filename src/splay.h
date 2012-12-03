#ifndef SPLAY_H
#define SPLAY_H

#include "bst.h"

class splay : public bst {
  virtual ~splay() {}
  virtual bool insert(int x);
  virtual bool contains(int x);
  virtual bool erase(int x);

  static bool insert(int x, node* &p);
  static bool contains(int x, node* &n, node** p, node** g);
  static bool erase(int x, node* &p);
  static void erase_node(node* &p);
  static void replace_with_successor(node* &p);
  static void replace_with_successor(node* &p, node* &s);

  static void do_splay(node* x, node** p, node** g);
  static void do_splay(node* x, node* &p);
  static void do_splay(node* x, node* &p, node* &g);
  static void right_rotation(node* &p);
  static void left_rotation(node* &p);
};

#endif

