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

Btree::Btree(BitVector _bitv, int _freq) {
  freq = _freq;
  bitv = _bitv;
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}

// // Public function to destroy the entire tree
// void Btree::destroy_tree() {
//   if (left != nullptr) {
//     left->destroy_tree();
//   }
//   if (right != nullptr) {
//     right->destroy_tree();
//   }
// }

// Public insert function
void Btree::insert(BitVector _bitv, int _freq) {
  if (left == nullptr) {
    Btree temp = Btree(_bitv,_freq);
    left = &temp;
    temp.parent = this;
  }
  else if (right == nullptr) {
    Btree temp = Btree(_bitv,_freq);
    right = &temp;
    temp.parent = this;
  } else {
    left->insert(_bitv,_freq);
  }
}

void Btree::insert(Btree *leaf) {
  if (left == nullptr) {
    left = leaf;
    leaf->parent = this;
  }
  else if (right == nullptr) {
    right = leaf;
    leaf->parent = this;
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
  return nullptr;
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

void treeTest() {
  // à mettre à jour
  /* // Tree Test
  Btree tree;

  // Inserting some values
  BitVector bitv1 = BitVector("1010");
  BitVector bitv2 = BitVector("1110");
  BitVector bitv3 = BitVector("1000");
  BitVector bitv4 = BitVector("1011");
  BitVector bitv5 = BitVector("1111");
  BitVector bitv6 = BitVector("0000");
  BitVector bitv7 = BitVector("0110");
  BitVector bitv8 = BitVector(10);

  cout << bitv8 << endl;
  cout << bitv7 << endl;

  tree.insert(bitv1, 5);
  tree.insert(bitv2, 3);
  tree.insert(bitv3, 7);
  tree.insert(bitv4, 2);
  tree.insert(bitv5, 4);
  tree.insert(bitv6, 6);
  tree.insert(bitv7, 8);

  // Printing the tree
  cout << "Tree structure:" << endl;
  tree.printing();

  node *result = tree.search(bitv1, 29);
  cout << result; */
}