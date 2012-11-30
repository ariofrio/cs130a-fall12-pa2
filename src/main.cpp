#include <iostream>
#include <cstring>
#include "iset.h"
#include "avl.h"
#include "bst.h"
#include "splay.h"

using namespace std;

bst* create_bst(string kind) {
  if(kind.compare("avl") == 0) {
    return new avl();
  } else if(kind.compare("bst") == 0) {
    return new bst();
  } else if(kind.compare("splay") == 0) {
    return new splay();
  } else {
    return NULL;
  }
}

int main(int argc, char** argv) {
  bst* set = create_bst(argv[0]);
  if(set == NULL) {
    cerr << "please rename this executable 'avl', 'bst', or 'splay'" << endl;
    return EXIT_FAILURE;
  }

  while(!cin.eof()) {
    string cmd;
    cin >> cmd;

    if(cmd.compare("insert") == 0) {
      int x;
      cin >> x;
      
      if(set->insert(x)) {
        cout << "Element inserted" << endl;
      } else {
        cout << "Element already present" << endl;
      }
    } else if(cmd.compare("access") == 0) {
      int x;
      cin >> x;

      if(set->contains(x)) {
        cout << "Element accessed" << endl;
      } else {
        cout << "Element not found" << endl;
      }
    } else if(cmd.compare("delete") == 0) {
      int x;
      cin >> x;

      if(set->erase(x)) {
        cout << "Element deleted" << endl;
      } else {
        cout << "Element not found" << endl;
      }
    } else if(cmd.compare("print") == 0) {
      set->print();
    }
  }
}

