#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "bitvector.h"
#include "tree.h"
#include "various_func.h"

void mainTest(string path) {
  // Main Test
  vector<char> byteData = read_file_bin(path, false);
  BitVector bitData = read_file_bit(path);

  // cout << bitData << "\n";
  // cout << bit_to_string(bitData) << "\n";

  map<char, int> dict_char = count_frequency_char(byteData);
  map<BitVector, int> dict_bit = count_frequency_bit(bitData, 8);

  read_dict(dict_char);
  read_dict(dict_bit);

  Btree tree = *dict_to_tree(dict_bit);

  cout << "Here is the tree" << endl;
  tree.printing();
  //cout << "Here is the text" << endl;
  //cout << bitData << endl;

  BitVector bitDataCompress = compress_text_static(bitData,tree);

  cout << endl;
  cout << "bitData has size " << bitData.size() << endl;
  cout << "bitDataCompress has size " << bitDataCompress.size() << endl;
  //cout << "Here is the compressed text" << endl;
  //cout << bitDataCompress << endl;

  cout << endl;
  BitVector bitDataDecompress = decompress_text_static(bitDataCompress,tree);
  cout << "bitDataDecompress has size " << bitDataDecompress.size() << endl;
  //cout << "Here is the text decompressed" << endl;
  //cout << bitDataDecompress << endl;
  //cout << bit_to_string(bitDataDecompress) << endl;


}

void compressbit_test(){
  BitVector bitv1 = BitVector("1010");
  BitVector bitv2 = BitVector("1110");
  BitVector bitv3 = BitVector("1000");
  BitVector bitv4 = BitVector("1011");
  BitVector bitv5 = BitVector("1111");
  BitVector bitv6 = BitVector("0000");
  BitVector bitv7 = BitVector("0110");

  Btree tree1 = Btree(bitv1, 54);
  Btree tree2 = Btree(bitv2, 41);
  Btree tree3 = Btree(bitv3, 34);
  Btree tree4 = Btree(bitv4, 31);
  Btree tree5 = Btree(bitv5, 25);
  Btree tree6 = Btree(bitv6, 17);
  Btree tree7 = Btree(bitv7, 9);

  tree1.insert(&tree2);
  tree1.insert(&tree3);
  tree2.insert(&tree4);
  tree2.insert(&tree5);
  tree3.insert(&tree6);
  tree3.insert(&tree7);

  BitVector bitc = compress_symbol(bitv6, tree1);

  cout << "Le vecteur compresse est : " << bitc << endl;
}