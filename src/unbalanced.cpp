#include "unbalanced.h"

bool unbalanced::insert(int x) {
  return insert(x, root);
}

bool unbalanced::insert(int x, node* &p) {
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

bool unbalanced::contains(int x) {
  return contains(x, root);
}

bool unbalanced::contains(int x, node* &p) {
  if(p == NULL) {
    return false;
  } else if(p->value == x) {
    return true;
  } else {
    bool ret;
    if(x < p->value) ret = contains(x, p->left);
    else ret = contains(x, p->right);
    return ret;
  }
}

bool unbalanced::erase(int x) {
  return erase(x, root);
}

bool unbalanced::erase(int x, node* &p) {
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
void unbalanced::erase_node(node* &p) {
  if(p->left == NULL && p->right == NULL) {
    delete p;
    p = NULL;
  } else if(p->left != NULL && p->right != NULL) {
    replace_with_successor(p);
  } else {
    node* child;
    if(p->left != NULL) child = p->left;
    else child = p->right;
    delete p;
    p = child;
  }
}

void unbalanced::replace_with_successor(node* &p) {
  replace_with_successor(p, p->right);
}

void unbalanced::replace_with_successor(node* &p, node* &s) {
  if(s->left == NULL) {
    p->value = s->value;
    erase_node(s); // never has left child
  } else {
    replace_with_successor(p, s->left);
  }
}

