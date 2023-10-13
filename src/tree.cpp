#include "tree.h"
#include "bitvector.h"

#include <iostream>
#include <queue>

Btree::Btree() { 
  freq = 0;
  bitv = BitVector();
  left = nullptr;
  right = nullptr;
  parent = nullptr;
 }

// Destructor
Btree::~Btree() { destroy_tree(); }

Btree::Btree(BitVector _bitv, int _freq) {
  freq = _freq;
  bitv = _bitv;
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}

// Public function to destroy the entire tree
void Btree::destroy_tree() {
  if (left != nullptr) {
    left->destroy_tree();
  }
  if (right != nullptr) {
    right->destroy_tree();
  }
}

// Public insert function
void Btree::insert(BitVector _bitv, int _freq) {
  if (left == nullptr) {
    Btree temp = Btree(_bitv,_freq);
    left = &temp;
  }
  else if (right == nullptr) {
    Btree temp = Btree(_bitv,_freq);
    right = &temp;
  } else {
    left->insert(_bitv,_freq);
  }
}

void Btree::insert(Btree *leaf) {
  if (left == nullptr) {
    left = leaf;
  }
  else if (right == nullptr) {
    left = leaf;
  } else {
    left->insert(leaf);
  }
}

// return the freq of root
int Btree::getRootFreq() { return freq; }

// Public search function
Btree *Btree::search(BitVector _bitv) {
  Btree* output;
  if (bitv == _bitv) {
    return this;
  }
  if (left != nullptr) {
    output = left->search(bitv);
    if (output != nullptr) { 
      return output;
      }
  }
  else if (right != nullptr) {
    output = right->search(bitv);
    if (output != nullptr) { 
      return output;
      }
  }
  else {
    return nullptr;
  }
}


void Btree::printing() {
  if (left == nullptr and right == nullptr and bitv == BitVector()) {
    std::cout << "Tree is empty." << std::endl;
    return;
  }

  std::queue<Btree *> q;
  q.push(this);

  while (!q.empty()) {
    int levelNodeCount = q.size(); // Number of nodes at the current level

    while (levelNodeCount > 0) {
      Btree *current = q.front();
      std::cout << current->freq << " ";
      std::cout << current->bitv << " ";
      q.pop();

      if (current->left != nullptr) {
        q.push(current->left);
      }
      if (current->right != nullptr) {
        q.push(current->right);
      }

      levelNodeCount--;
    }
    std::cout
        << std::endl; // Move to the next line for the next level of the tree
  }
}