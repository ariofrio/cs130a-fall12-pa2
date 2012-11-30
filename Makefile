CXXFLAGS=-std=gnu++0x
LDFLAGS=

SRC=\
     src/main.o \
     src/binary_tree.o \
     src/bst.o \
     src/avl.o \
     src/splay.o

all: bst avl splay

.PHONY: all test clean

bst: $(SRC)
	$(CXX) $(LDFLAGS) $^ -o $@

avl: bst
	cp bst avl

splay: bst
	cp bst splay

test: all
	test/run_all.sh

clean:
	rm -f $(SRC)
	rm -f bst avl splay

