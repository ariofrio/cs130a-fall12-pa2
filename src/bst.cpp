#include "bst.h"

bool bst::insert(int x) {
  node** node = find(x);
  if(*node == NULL) {
    *node = new struct node(x);
    return true;
  } else {
    return false; // already present
  }
}

bool bst::contains(int x) {
  node** node = find(x);
  if(*node == NULL) {
    return false;
  } else {
    return true;
  }
}

bool bst::erase(int x) {
  node** node = find(x);
  if((*node) == NULL) {
    return false;
  } else {
    if((*node)->left == NULL && (*node)->right == NULL) {
      delete *node;
      *node = NULL;
    } else if((*node)->left != NULL && (*node)->left != NULL) {
      //find_smallest(&((*node)->right));
      // TODO!
    } else if((*node)->left != NULL) {
    } else if((*node)->right != NULL) {
    } else {
      throw "great scott! this is impossible! see bst.cpp";
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
