#ifndef TREE_H
#define TREE_H

#include "bitvector.h"

struct node {
  int freq;
  BitVector bitv;
  struct node *left;  // Reference to left child
  struct node *right; // Reference to right child
};

class Btree {
public:
  Btree();
  ~Btree();
  Btree(BitVector bitv, int freq);

  void insert(BitVector bitv, int freq);
  void insert(Btree *leaf);
  void printing();
  Btree *search(BitVector bitv);
  void destroy_tree();
  int getRootFreq();

  int freq;
  BitVector bitv;
  Btree *left;  // Reference to left child
  Btree *right; // Reference to right child
  Btree *parent; //Reference to parent
};

#endif // TREE_H