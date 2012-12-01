#include "bst.h"

bool bst::insert(int x) {
  node** n = find(x);
  if(*n == NULL) {
    *n = new struct node(x);
    return true;
  } else {
    return false; // already present
  }
}

bool bst::contains(int x) {
  node** n = find(x);
  if(*n == NULL) {
    return false;
  } else {
    return true;
  }
}

bool bst::erase(int x) {
  erase(find(x));
}

bool bst::erase(node** n) {
  if((*n) == NULL) {
    return false;
  } else {
    if((*n)->left == NULL && (*n)->right == NULL) {
      delete *n;
      *n = NULL;
    } else if((*n)->left != NULL && (*n)->right != NULL) {
      node** successor = find_smallest(&((*n)->right));
      (*n)-> value = (*successor)->value;
      erase(successor);
    } else {
      node* child;
      if((*n)->left != NULL) {
        child = (*n)->left;
      } else {
        node* child = (*n)->right;
      }

      delete *n;
      *n = child;
    }
    return true;
  }
}

bst::node** bst::find(int x) {
  node** current = &root;
  while(*current != NULL) {
    if((*current)->value == x)
      break;
    else if(x < (*current)->value)
      current = &((*current)->left);
    else
      current = &((*current)->right);
  }
  return current;
}

bst::node** bst::find_smallest(node** root) {
  if((*root)->left == NULL) {
    return root;
  } else {
    return find_smallest(&((*root)->left));
  }
}
