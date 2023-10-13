#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "bitvector.h"
#include "tree.h"

using namespace std;

BitVector read_file_bit(const string &path) {
  BitVector bitData;
  ifstream file(path, ios::binary | ios::ate);
  streamsize size = file.tellg();
  file.seekg(0, ios::beg);
  if (size > 0) {
    vector<char> byteData(size);
    
    if (file.read(byteData.data(), size)) {
      // byteData now contains the file's contents as bytes
      for (char i : byteData) {
        bitset<8> octet = bitset<8>(i);
        for (int j = 0; j < 8; j++) {
          bitData.push_back(bool(octet[j]));
        }
      }
    }
  }
  return bitData;
}

vector<char> read_file_bin(const string &path, bool afficher) {
  ifstream file(path, ios::binary | ios::ate);
  streamsize size = file.tellg();
  file.seekg(0, ios::beg);
  vector<char> byteData;
  if (size > 0) {
    byteData.resize(size);
    if (file.read(byteData.data(), size) && afficher == true) {
      // byteData now contains the file's contents as bytes
      for (char i : byteData)
        cout << bitset<8>(i) << " ";
    }
  }
  return byteData;
}

map<char, int> count_frequency_char(vector<char> byteData) {
  map<char, int> dict;
  for (unsigned int i = 0; i < byteData.size(); i++) {
    char c = byteData[i];
    if (dict.count(c)) {
      dict[c]++;
    } else {
      dict[c] = 1;
    }
  }

  return dict;
}

map<BitVector, int> count_frequency_bit(BitVector bitData, int n) {
  map<BitVector, int> dict;
  for (unsigned int i = 0; i < bitData.size(); i = i + n) {
    BitVector v;
    if (i + n <= bitData.size()) {
      v = bitData.sliceSE(i, i + n);
    } else {
      v = bitData.sliceS(i) + BitVector(i + n - bitData.size());
    }
    if (dict.count(v)) {
      dict[v]++;
    } else {
      dict[v] = 1;
    }
  }

  return dict;
}

void read_dict(map<char, int> dict) {
  map<char, int>::iterator i;
  cout << "Keys"
       << "  &  "
       << "Value" << endl;
  for (i = dict.begin(); i != dict.end(); i++) {
    cout << (*i).first << "    " << (*i).second << "\n";
  }
}

void read_dict(map<BitVector, int> dict) {
  map<BitVector, int>::iterator i;
  cout << "Keys"
       << "  &  "
       << "Value" << endl;
  for (i = dict.begin(); i != dict.end(); i++) {
    cout << (*i).first << "    " << (*i).second << "\n";
  }
}

vector<char> bit_to_char(const BitVector vec) {
  size_t size = vec.size();
  vector<char> output;
  for (size_t i = 0; i + 8 <= size; i = i + 8) {
    BitVector bitvec = vec.sliceSE(i, i + 8);
    char c = 0;
    for (int j = 0; j < 8; j++) {
      c = c | (bitvec[j] << j);
    }
    output.push_back(c);
  }
  return output;
}

string bit_to_string(const BitVector vec) {
  size_t size = vec.size();
  string output;
  for (size_t i = 0; i + 8 <= size; i = i + 8) {
    BitVector bitvec = vec.sliceSE(i, i + 8);
    char c = 0;
    for (int j = 0; j < 8; j++) {
      c = c | (bitvec[j] << j);
    }
    output.push_back(c);
  }
  return output;
}

void printVector(const vector<BitVector> vec) {
  cout << "[";
  for (BitVector v : vec) {
    cout /* << v << ":" */ << bit_to_string(v) << ",";
  }
  cout << "] \n";
}

Btree dict_to_tree(map<BitVector, int> dict) {
  Btree outTree = Btree();
  // first we need to sort the dict so we have a list of value with increasing
  // frequency
  vector<BitVector> sortedList;
  map<BitVector, int>::iterator it;
  for (it = dict.begin(); it != dict.end(); it++) {
    sortedList.push_back((*it).first);
  }
  // insertion sort copy pasted from wikipedia
  size_t j = 1;
  long long int k = 1;
  BitVector temp;
  while (j < sortedList.size()) {
    temp = sortedList[j];
    k = j - 1;
    while (k >= 0 && dict[sortedList[k]] > dict[temp]) {
      sortedList[k + 1] = sortedList[k];
      k = k - 1;
    }
    sortedList[k + 1] = temp;
    j = j + 1;
  }

  vector<Btree *> BtreeList;
  for (BitVector v : sortedList) {
    BtreeList.push_back(new Btree(v, dict[v]));
  }

  for (Btree *t : BtreeList) {
    t->printing();
  }

  return outTree;
}

/*
BitVector compress_symbol(BitVector bitv, Btree btree){

  if (bitv == nullptr) {
    cout << "Tree is empty." << endl;
    return;
  }

  std::queue<node *> q;
  q.push(bitv);

  while (!q.empty()) {
    int levelNodeCount = q.size(); // Number of nodes at the current level

    while (levelNodeCount > 0) {
      node *current = q.front();
      q.pop();

      if (current->left != nullptr) {
        q.push(current->left);
      }
      if (current->right != nullptr) {
        q.push(current->right);
      }

      levelNodeCount--;
    }
    cout << endl; // Move to the next line for the next level of the
tree
  }

  return bitv_comp;
}*/