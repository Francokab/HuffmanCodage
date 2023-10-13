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
//  - fonction tree + bitvector => bitvector compressé
//  - fonction tree + texte => texte compressé
//  - fonction tree + texte compressé => texte
//  - méthode adaptatif
//  - (Bonus) count_frequency_dinamique (variable size keys)

int main() {

  //treeTest();

  string path = "text/text_court.txt";
  mainTest(path);

  // BitVectorTest();
  return 0;
}