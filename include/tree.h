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
  void printing();
  node *search(BitVector bitv, int freq);
  void destroy_tree();
  int getRootFreq();

private:
  void destroy_tree(node *leaf);
  void insert(BitVector bitv, int freq, node *leaf);
  node *search(BitVector bitv, int freq, node *leaf);

  node *root;
};

#endif // TREE_H