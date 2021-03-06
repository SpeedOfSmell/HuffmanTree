
// heap.hpp -- heap header
// c. 2015 A. Deeter, revisions c. 2015 C. Reilly

// making a heap

#ifndef HEAP_HPP
#define HEAP_HPP

#include "HNode.hpp"
#include <vector>

class Heap {
    protected:
      // holds the tree
      std::vector<HNode*> tree;

      // index of the last element added
      int position = 0;

    public:
      int count=0;

      Heap() {
      //tree.resize(2);
      }
      ~Heap() {}

      // add an element to the tree
      void enqueue( HNode*);
      // fix the heap from a specific index up
      void fix_up(int);

      // remove the smallest element
      HNode* dequeue();
      // fix the tree after replacing the smallest element
      void fix_down(int);

      int parent(int);
      int leftChild(int);
      int rightChild(int);

      void print();

      void clear();
};

#endif
