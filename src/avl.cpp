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
      ensure_balanced(x, current);
      update_height(current);
    }
    return ret;
  }
}

bool avl::erase(int x) {
  return erase_from(x, root);
}

bool avl::erase_from(int x, node* &current) {/*
  if(current == NULL) {
    return false;
  } else if(current->value == x) {
    if(current->left == NULL && current->right == NULL) {
      delete current;
      current = NULL;
    } else if(current->left != NULL && current->right != NULL) {
      node* &successor = *bst::find_smallest(&(current->right));
      current->value = successor->value;
      erase_from(successor);
    } else {
      node* child;
      if(current->left != NULL) {
        child = current->left;
      } else {
        child = current->right;
      }

      delete current;
      current = child;
    }
    return true;
  } else {
    bool ret;
    if(x < current->value) {
      ret = erase_from(x, current->left);
    } else {
      ret = erase_from(x, current->right);
    }
    if(ret) {
      ensure_balanced(x, current);
      update_height(current);
    }
    return ret;
  }
*/}

void avl::ensure_balanced(int x, node* &current) {
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

