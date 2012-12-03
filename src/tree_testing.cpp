#include "bst.h"
#include "unbalanced.h"
#include "avl.h"
#include "splay.h"
#include <cstdlib>
#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <cstring>

const int N = 10000;
bool VERBOSE = true;

static timeval begin;
static timeval end;

void start_stopwatch() {
  gettimeofday(&begin, NULL);
}

void stop_stopwatch() {
  gettimeofday(&end, NULL);

  static timeval diff;
  timersub(&end, &begin, &diff);

  {
    using namespace std;
    if(VERBOSE) cout << "    ";
    if(VERBOSE) cout << setfill(' ') << setw(7);
    cout << diff.tv_sec * 1000000 + diff.tv_usec;
    //cout << "    " << diff.tv_sec << '.';
    //cout << setfill('0') << setw(6) << diff.tv_usec;
    if(VERBOSE) cout << "us";
    cout << endl;
  }
}

// insert in increasing order, 
// access in increasing order,
// delete in increasing order
void test_1(bst* bst) {
  start_stopwatch();
  for(int x=0; x<N; x++)
    bst->insert(x);
  stop_stopwatch();
  start_stopwatch();
  for(int x=0; x<N; x++)
    if(bst->contains(x) == false) exit(1);
  stop_stopwatch();
  start_stopwatch();
  for(int x=0; x<N; x++)
    bst->erase(x);
  stop_stopwatch();
}

// insert in increasing order, 
// access in decreasing order,
// delete in decreasing order
void test_2(bst* bst) {
  start_stopwatch();
  for(int x=0; x<N; x++)
    bst->insert(x);
  stop_stopwatch();
  start_stopwatch();
  for(int x=N-1; x>=0; x--)
    if(bst->contains(x) == false) exit(1);
  stop_stopwatch();
  start_stopwatch();
  for(int x=N-1; x>=0; x--)
    bst->erase(x);
  stop_stopwatch();
}

// insert in random order, 
// access in same random order,
// delete in same random order
void test_3(bst* bst) {
  std::vector<int> v(N);
  std::set<int> s;
  while(v.size() < N) {
    int n = rand()/RAND_MAX*N*3;
    if(s.find(n) != s.end()) { // if n is not in s
      v.push_back(n);
      s.insert(n);
    }
  }

  start_stopwatch();
  for(int x=0; x<N; x++)
    bst->insert(v[x]);
  stop_stopwatch();
  start_stopwatch();
  for(int x=0; x<N; x++)
    if(bst->contains(v[x]) == false) exit(1);
  stop_stopwatch();
  start_stopwatch();
  for(int x=0; x<N; x++)
    bst->erase(v[x]);
  stop_stopwatch();
}


void test(bst* bst) {
  if(VERBOSE) std::cout << "  test 1:" << std::endl;
  test_1(bst);
  if(VERBOSE) std::cout << "  test 2:" << std::endl;
  test_2(bst);
  if(VERBOSE) std::cout << "  test 3:" << std::endl;
  test_3(bst);
}

int main(int argc, char** argv) {
  if(argc > 1 && strcmp(argv[1], "--quiet") == 0) {
    VERBOSE = false;
  }

  bst* bst;

  if(VERBOSE) std::cout << "bst:" << std::endl;
  bst = new unbalanced();
  test(bst);
  delete bst;

  if(VERBOSE) std::cout << "avl:" << std::endl;
  bst = new avl();
  test(bst);
  delete bst;

  if(VERBOSE) std::cout << "splay:" << std::endl;
  bst = new splay();
  test(bst);
  delete bst;
}

