#include "binary_tree.h"
#include <iostream>

void binary_tree::print() const {
  print_preorder(root);
  std::cout << std::endl;
  print_inorder(root);
  std::cout << std::endl;
}

void binary_tree::print_preorder(const node* const root) const {
  if(root == NULL) return;
  std::cout << root->value << " ";
  print_preorder(root->left);
  print_preorder(root->right);
}

void binary_tree::print_inorder(const node* const root) const {
  if(root == NULL) return;
  print_inorder(root->left);
  std::cout << root->value << " ";
  print_inorder(root->right);
}
