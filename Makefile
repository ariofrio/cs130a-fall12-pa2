CXXFLAGS=-std=gnu++0x
LDFLAGS=

SRC=\
     src/avl.o \
     src/binary_tree.o \
     src/main.o \
     src/splay.o \
     src/unbalanced.o

HEADERS=\
     src/avl.h \
     src/binary_tree.h \
     src/bst.h \
     src/splay.h \
     src/unbalanced.h

all: bst avl splay

.PHONY: all test clean

bst: $(SRC) $(HEADERS)
	$(CXX) $(LDFLAGS) $(SRC) -o $@

avl: bst
	cp bst avl

splay: bst
	cp bst splay

test: all
	test/run_all.sh

clean:
	rm -f $(SRC)
	rm -f bst avl splay

