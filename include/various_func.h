#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "bitvector.h"
#include "tree.h"

using namespace std;

BitVector read_file_bit(const string &path);
vector<char> read_file_bin(const string &path, bool afficher);
map<char, int> count_frequency_char(vector<char> byteData);
map<BitVector, int> count_frequency_bit(BitVector bitData, int n);
void read_dict(map<char, int> dict);
void read_dict(map<BitVector, int> dict);
vector<char> bit_to_char(const BitVector vec);
string bit_to_string(const BitVector vec);
void printVector(const vector<BitVector> vec);
Btree *dict_to_tree(map<BitVector, int> dict);
BitVector compress_symbol(BitVector bitv, Btree btree);
void mainTest(string path);
void compressbit_test();