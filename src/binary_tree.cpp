#include "binary_tree.h"
#include <iostream>

bool binary_tree::verbose = false;

void binary_tree::print() const {
  print_preorder(root);
  std::cout << std::endl;
  print_inorder(root);
  std::cout << std::endl;
  if(verbose) {
    print_unique(root);
    std::cout << std::endl;
  }
}

void binary_tree::print_preorder(const node* const root) {
  if(root == NULL) return;
  std::cout << root->value << " ";
  print_preorder(root->left);
  print_preorder(root->right);
}

void binary_tree::print_inorder(const node* const root) {
  if(root == NULL) return;
  print_inorder(root->left);
  std::cout << root->value << " ";
  print_inorder(root->right);
}

void binary_tree::print_unique(const node* const root) {
  if(root == NULL) return;
  std::cout << root->value << ":" << root->data;
  if(root->left != NULL || root->right != NULL) {
    std::cout << "(";
    print_unique(root->left);
    std::cout << ",";
    print_unique(root->right);
    std::cout << ")";
  }
}
