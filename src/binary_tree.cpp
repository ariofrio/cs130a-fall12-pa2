#include "binary_tree.h"

void binary_tree::print() const {
  print_preorder(root);
  cout << endl;
  print_inorder(root);
  cout << endl;
}

void binary_tree:print_preorder(const node* const root) const {
  cout << root << " ";
  if(root->left != NULL) print_preorder(root->left);
  if(root->right != NULL) print_preorder(root->right);
}

void binary_tree:print_inorder(const node* const root) const {
  if(root->left != NULL) print_inorder(root->left);
  cout << root << " ";
  if(root->right != NULL) print_inorder(root->right);
}
