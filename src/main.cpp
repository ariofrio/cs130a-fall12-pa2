#include <iostream>
#include <cstring>
#include "bst.h"
#include "avl.h"
#include "splay.h"

using namespace std;

bool ends_with(string const &haystack, string const &suffix) {
  if(haystack.length() >= suffix.length()) {
    return 0 == haystack.compare(
        haystack.length()-suffix.length(),
        suffix.length(), suffix);
  } else {
    return false;
  }
}

bst* create_bst(string kind) {
  if(ends_with(kind, "avl")) {
    return new avl();
  } else if(ends_with(kind, "bst")) {
    return new bst();
  } else if(ends_with(kind, "splay")) {
    return new splay();
  } else {
    return NULL;
  }
}

int main(int argc, char** argv) {
  bst* bst= create_bst(argv[0]);
  if(bst== NULL) {
    cerr << "please rename this executable 'avl', 'bst', or 'splay'" << endl;
    return EXIT_FAILURE;
  }

  while(!cin.eof()) {
    string cmd;
    cin >> cmd;

    if(cmd.compare("insert") == 0) {
      int x;
      cin >> x;
      
      if(bst->insert(x)) {
        cout << "Element inserted" << endl;
      } else {
        cout << "Element already present" << endl;
      }
    } else if(cmd.compare("access") == 0) {
      int x;
      cin >> x;

      if(bst->contains(x)) {
        cout << "Element accessed" << endl;
      } else {
        cout << "Element not found" << endl;
      }
    } else if(cmd.compare("delete") == 0) {
      int x;
      cin >> x;

      if(bst->erase(x)) {
        cout << "Element deleted" << endl;
      } else {
        cout << "Element not found" << endl;
      }
    } else if(cmd.compare("print") == 0) {
      bst->print();
    }
  }
}

