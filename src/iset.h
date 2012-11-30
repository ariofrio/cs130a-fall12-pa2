#ifndef ISET_H
#define ISET_H

class iset { // a virtual base class for set implementations
public:
  virtual ~iset() {}
  virtual bool insert(int x) = 0;
  virtual bool contains(int x) = 0;
  virtual bool erase(int x) = 0;
};

#endif

