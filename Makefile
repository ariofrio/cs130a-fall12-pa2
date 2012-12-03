CXXFLAGS=-std=gnu++0x
LDFLAGS=

SRC=\
     src/avl.o \
     src/binary_tree.o \
     src/splay.o \
     src/unbalanced.o

HEADERS=\
     src/avl.h \
     src/binary_tree.h \
     src/bst.h \
     src/splay.h \
     src/unbalanced.h

all: bst avl splay tree_testing

.PHONY: all test bench clean

tree_testing: $(SRC) src/tree_testing.o $(HEADERS)
	$(CXX) $(LDFLAGS) $(SRC) src/tree_testing.o -o $@

bst: $(SRC) src/main.o $(HEADERS)
	$(CXX) $(LDFLAGS) $(SRC) src/main.o -o $@

avl: bst
	cp bst avl

splay: bst
	cp bst splay

test: bst avl splay
	test/run_all.sh

bench: tree_testing
	./tree_testing $(BENCHFLAGS)

clean:
	rm -f $(SRC)
	rm -f bst avl splay tree_testing

