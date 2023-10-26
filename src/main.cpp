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

  entropie_test();
  
  // Btree tree = *dict_to_tree(dict_bit); //O(c.log(c))

  // BitVector bitDataCompress = compress_text_static(bitData,tree);

  // cout << "size compress : " << bitDataCompress.size() << endl;

  // ofstream fluxcomp("text/text_comp.txt");
  // fluxcomp << bit_to_string(bitDataCompress);

  // BitVector bitDataDecompress = decompress_text_static(bitDataCompress, tree);

  // ofstream fluxdecomp("text/text_decomp.txt");
  // fluxdecomp << bit_to_string(bitDataDecompress);

  return 0;
}