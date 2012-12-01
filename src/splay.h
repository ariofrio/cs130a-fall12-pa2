#ifndef SPLAY_H
#define SPLAY_H

#include "bst.h"

class splay : public bst {
  virtual ~splay() {}
  virtual bool insert(int x) {}
  virtual bool contains(int x) {}
  virtual bool erase(int x) {}
};

#endif

