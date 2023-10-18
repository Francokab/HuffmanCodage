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

// TODO
//  - fonction tree + texte compressé => texte
//  - (Bonus) méthode adaptatif
//  - (Bonus) count_frequency_dinamique (variable size keys)

int main() {

  mainTest("text/text_court.txt");

  return 0;
}