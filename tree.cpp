#include "tree.h"
#include "bitvector.h"

#include <iostream>
#include <queue>

Btree::Btree() { root = nullptr; }

// Destructor
Btree::~Btree() { destroy_tree(); }

Btree::Btree(BitVector bitv, int freq) {
  root = nullptr;
  this->insert(bitv, freq);
}

// Public function to destroy the entire tree
void Btree::destroy_tree() { destroy_tree(root); }

// Private recursive function to destroy the tree from a given node downwards
void Btree::destroy_tree(node *leaf) {
  if (leaf != nullptr) {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

// Public insert function
void Btree::insert(BitVector bitv, int freq) {
  // If the tree is empty
  if (root == nullptr) {
    std::cout << "test3 \n";
    root = new node{freq, bitv, nullptr, nullptr};
  } else {
    insert(bitv, freq, root);
  }
}

void Btree::insert(BitVector bitv, int freq, node *leaf) {
  if (freq < leaf->freq) {
    if (leaf->left != nullptr) {
      insert(bitv, freq, leaf->left);
    } else {
      leaf->left = new node{freq, bitv, nullptr, nullptr};
    }
  } else if (freq > leaf->freq) {
    if (leaf->right != nullptr) {
      insert(bitv, freq, leaf->right);
    } else {
      leaf->right = new node{freq, bitv, nullptr, nullptr};
    }
  }
}

// return the freq of root
int Btree::getRootFreq() { return root->freq; }

// Public search function
node *Btree::search(BitVector bitv, int freq) {
  return search(bitv, freq, root);
}

// Private recursive helper function for search
node *Btree::search(BitVector bitv, int freq, node *leaf) {
  // Base cases
  if (leaf == nullptr) {
    return nullptr; // Key not found in the tree
  } else if (bitv == leaf->bitv) {
    return leaf; // Key found, return the node
  }

  // Recursive cases
  if (bitv < leaf->bitv) {
    return search(bitv, freq, leaf->left); // Search left subtree
  } else {
    return search(bitv, freq, leaf->right); // Search right subtree
  }
}

void Btree::printing() {
  if (root == nullptr) {
    std::cout << "Tree is empty." << std::endl;
    return;
  }

  std::queue<node *> q;
  q.push(root);

  while (!q.empty()) {
    int levelNodeCount = q.size(); // Number of nodes at the current level

    while (levelNodeCount > 0) {
      node *current = q.front();
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