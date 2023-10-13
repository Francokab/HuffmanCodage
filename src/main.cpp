#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "bitvector.h"
#include "tree.h"
#include "various_func.h"

using namespace std;

// TODO
//  - Création d'une classe tree good
//  - fonction dict => tree
//  - fonction tree + bitvector => bitvector compressé
//  - fonction tree + texte => texte compressé
//  - fonction tree + texte compressé => texte
//  - méthode adaptatif
//  - (Bonus) count_frequency_dinamique (variable size keys)

int main() {

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
  
  // Main Test
  vector<char> byteData = read_file_bin("text/text_tres_court.txt", false);
  BitVector bitData = read_file_bit("text/text_tres_court.txt");

  // cout << bitData << "\n";
  // cout << bit_to_string(bitData) << "\n";

  map<char, int> dict_char = count_frequency_char(byteData);
  map<BitVector, int> dict_bit = count_frequency_bit(bitData, 8);

  read_dict(dict_char);
  read_dict(dict_bit);

  dict_to_tree(dict_bit);

  // BitVector Test
  /* BitVectorTest(); */
  return 0;
}