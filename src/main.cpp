#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "bitvector.h"
#include "tree.h"
#include "various_func.h"
#include "test.h"

using namespace std;


int main() {

  BitVector bitData = read_file_bit("text/text.txt");

  map<BitVector, int> dict_bit = count_frequency_bit(bitData, 8);

  Btree tree = *dict_to_tree(dict_bit);

  BitVector bitDataCompress = compress_text_static(bitData,tree);

  ofstream flux("text/text_comp.txt");
  flux << bit_to_string(bitDataCompress) << endl;

  return 0;
}