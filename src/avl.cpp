#include <algorithm>
#include <iostream>
#include "avl.h"

bool avl::insert(int x) {
  return insert_into(x, root);
}

bool avl::insert_into(int x, node* &current) {
  if(current == NULL) {
    current = new struct node(x, 0);
    return true;
  } else if(current->value == x) {
    return false;
  } else {
    bool ret;
    if(x < current->value) {
      ret = insert_into(x, current->left);
    } else {
      ret = insert_into(x, current->right);
    }
    if(ret) {
      if(height(current->left) - 
          height(current->right) == 2) {

        if(x < current->left->value) {
          rotate_with_left_child(current);
        } else {
          rotate_with_right_child(current->left);
          rotate_with_left_child(current);
        }

      } else if(height(current->right) - 
          height(current->left) == 2) {

        if(current->right->value < x) {
          rotate_with_right_child(current);
        } else {
          rotate_with_left_child(current->right);
          rotate_with_right_child(current);
        }

      }
      update_height(current);
    }
    return ret;
  }
}

void avl::rotate_with_left_child(node* &q) {
  node* p = q->left;
  q->left = p->right;
  p->right = q;
  update_height(q);
  update_height(p);
  q = p;
}

void avl::rotate_with_right_child(node* &q) {
  node* p = q->right;
  q->right = p->left;
  p->left = q;
  update_height(q);
  update_height(p);
  q = p;
}

void avl::update_height(node* p) {
  p->data = 1 + std::max(height(p->left), height(p->right));
}

int avl::height(const node* const p) const {
  if(p == NULL) {
    return -1;
  } else {
    return p->data;
  }
}

