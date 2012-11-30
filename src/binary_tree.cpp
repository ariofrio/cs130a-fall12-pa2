#include "binary_tree.h"

void binary_tree::print() const {
  print_preorder(root);
  std::cout << std::endl;
  print_inorder(root);
  std::cout << std::endl;
}

void binary_tree::print_preorder(const node* const root) const {
  std::cout << root->value << " ";
  if(root->left != NULL) print_preorder(root->left);
  if(root->right != NULL) print_preorder(root->right);
}

void binary_tree::print_inorder(const node* const root) const {
  if(root->left != NULL) print_inorder(root->left);
  std::cout << root->value << " ";
  if(root->right != NULL) print_inorder(root->right);
}
