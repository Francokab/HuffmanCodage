#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "bitvector.h"
#include "tree.h"

using namespace std;

// TODO
//  - Création d'arbre des fréquences
BitVector read_file_bit(const string &path) {
  ifstream file(path, ios::binary | ios::ate);
  streamsize size = file.tellg();
  file.seekg(0, ios::beg);

  vector<char> byteData(size);
  BitVector bitData;
  if (file.read(byteData.data(), size)) {
    // byteData now contains the file's contents as bytes
    for (char i : byteData) {
      bitset<8> octet = bitset<8>(i);
      for (int j = 0; j < 8; j++) {
        bitData.push_back(bool(octet[j]));
      }
    }
  }

  return bitData;
}

vector<char> read_file_bin(const string &path, bool afficher) {
  ifstream file(path, ios::binary | ios::ate);
  streamsize size = file.tellg();
  file.seekg(0, ios::beg);

  vector<char> byteData(size);
  if (file.read(byteData.data(), size) && afficher == true) {
    // byteData now contains the file's contents as bytes
    for (char i : byteData)
      cout << bitset<8>(i) << " ";
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
    for (int j = 0; j < n; j++) {
      bitData[j];
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
  for (int i = 0; i + 8 <= size; i = i + 8) {
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
  for (int i = 0; i + 8 <= size; i = i + 8) {
    BitVector bitvec = vec.sliceSE(i, i + 8);
    char c = 0;
    for (int j = 0; j < 8; j++) {
      c = c | (bitvec[j] << j);
    }
    output.push_back(c);
  }
  return output;
}

int main() {

  // Tree Test
  /* btree tree;

  // Inserting some values
  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(2);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);

  // Printing the tree
  cout << "Tree structure:" << endl;
  tree.printing();

  node *result = tree.search(29);
  cout << result; */

  // Main Test
  BitVector bitData = read_file_bit("text_tres_court.txt");
  vector<char> byteData = read_file_bin("text_tres_court.txt", false);

  cout << bitData << "\n";
  cout << bit_to_string(bitData) << "\n";

  // map<char, int> dict_char = count_frequency_char(byteData);
  // map<BitVector, int> dict_bit = count_frequency_bit(bitData, 8);

  // read_dict(dict_char);
  // read_dict(dict_bit);

  // BitVector Test
  // BitVectorTest();
  return 0;
}