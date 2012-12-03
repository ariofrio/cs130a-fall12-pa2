#include "splay.h"
#include <iostream>

bool splay::insert(int x) {
  return insert(x, root);
}

bool splay::insert(int x, node* &p) {
  if(p == NULL) {
    p = new struct node(x);
    return true;
  } else if(p->value == x) {
    return false;
  } else {
    bool ret;
    if(x < p->value) ret = insert(x, p->left);
    else ret = insert(x, p->right);
    return ret;
  }
}

bool splay::contains(int x) {
  return contains(x, root, NULL, NULL);
}

bool splay::contains(int x, node* &n, node** p, node** g) {
  static bool splay;
  if(n == NULL) {
    return false;
  } else {
    bool ret;
    if(n->value == x) {
      ret = true;
      splay = true;
    } else {
      if(x < n->value)
        ret = contains(x, n->left, &n, p);
      else
        ret = contains(x, n->right, &n, p);
      splay = !splay;
    }
    if(splay || (splay && g == NULL && p != NULL)) {
      // print();
      do_splay(n, p, g);
    }
    return ret;
  }
}

bool splay::erase(int x) {
  contains(x); // splay the node to be deleted by accessing it 
  return erase(x, root);
}

bool splay::erase(int x, node* &p) {
  if(p == NULL) {
    return false;
  } else if(p->value == x) {
    erase_node(p);
    return true;
  } else {
    bool ret;
    if(x < p->value) ret = erase(x, p->left);
    else ret = erase(x, p->right);
    return ret;
  }
}

// p must not be NULL
void splay::erase_node(node* &p) {
  if(p->left == NULL && p->right == NULL) {
    delete p;
    p = NULL;
  } else if(p->left != NULL && p->right != NULL) {
    replace_with_predecessor(p);
  } else {
    node* child;
    if(p->left != NULL) child = p->left;
    else child = p->right;
    delete p;
    p = child;
  }
}

void splay::replace_with_predecessor(node* &p) {
  replace_with_predecessor(p, p->left);
}

void splay::replace_with_predecessor(node* &p, node* &s) {
  if(s->right == NULL) {
    p->value = s->value;
    erase_node(s); // never has right child
  } else {
    replace_with_predecessor(p, s->right);
  }
}

void splay::do_splay(node* x, node** p, node** g) {
  if(p == NULL) {
    return;
  } else if(g == NULL) {
    do_splay(x, *p);
  } else {
    do_splay(x, *p, *g);
  }
}

void splay::do_splay(node* x, node* &p) { // zig ztep
  if(x == p->left) {
    right_rotation(p);
  } else {
    left_rotation(p);
  }
}

void splay::do_splay(node* x, node* &p, node* &g) {
  if(x == p->left && p == g->left) { // zig-zig step
    right_rotation(g);
    right_rotation(g);
  } else if(x == p->right && p == g->right) { // zig-zig step
    left_rotation(g);
    left_rotation(g);
  } else if(x == p->right && p == g->left) { // zig-zag step
    left_rotation(p);
    right_rotation(g);
  } else if(x == p->left && p == g->right) { // zig-zag step
    right_rotation(p);
    left_rotation(g);
  }
}

void splay::right_rotation(node* &p) {
  node* x = p->left;
  p->left = x->right;
  x->right = p;
  p = x;
}

void splay::left_rotation(node* &p) {
  node* x = p->right;
  p->right = x->left;
  x->left = p;
  p = x;
}

