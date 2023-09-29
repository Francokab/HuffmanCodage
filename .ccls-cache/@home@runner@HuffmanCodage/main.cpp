#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <map>

using namespace std;

//TODO
// - Changer read_file en Vector_Bool
// - Changer count_frequency_bit pour marcher avec vector_bool
// - Faire un objet basic pour les arbres (arbre binaire)
// - Création d'arbre des fréquences
vector<int> read_file_bit(const string& path){
  ifstream file(path, ios::binary | ios::ate);
  streamsize size = file.tellg();
  file.seekg(0, ios::beg);

  vector<char> byteData(size);
  bitset<8*size> bitData;
  if (file.read(byteData.data(), size)) {
    // byteData now contains the file's contents as bytes
    string octet;
    for (char i: byteData){
      octet = bitset<8>(i).to_string();
      for (char j: octet){
        bitData.push_back(int(j));
      }
    }   
  }

  return bitData;
}

vector<char> read_file_bin(const string& path, bool afficher) {
  ifstream file(path, ios::binary | ios::ate);
  streamsize size = file.tellg();
  file.seekg(0, ios::beg);

  vector<char> byteData(size);
  if (file.read(byteData.data(), size) && afficher == true) {
    // byteData now contains the file's contents as bytes
    for (char i: byteData) cout << bitset<8>(i) << " ";
  }

  return byteData;
}

map<char,int> count_frequency_char(vector<char> byteData){
  map<char,int> dict;
  for(unsigned int i = 0; i < byteData.size(); i++) {
    char c = byteData[i];
    if (dict.count(c)){
      dict[c]++;
    }
    else{
      dict[c] = 1;
    }
  }

  return dict;
}

void read_dict(map<char, int> dict){
  map <char,int> :: iterator i;
  cout<<"Keys"<<"  &  "<<"Value"<<endl;
  for (i = dict.begin(); i!= dict.end(); i++)
  {
     cout<<(*i).first<<"    "<<(*i).second<<"\n";
  }
}

map<char,int> count_frequency_bit(vector<int> bitData,int n){
  map<char,int> dict;
  for(unsigned int i = 0; i < bitData.size(); i = i + n) {
    string s;
    for (int j = 0; j < n; j++){
      bitData[j];
    }
    if (dict.count(c)){
      dict[c]++;
    }
    else{
      dict[c] = 1;
    }
  }

  return dict;
}


int main() {

  vector<int> bitData = read_file_bit("text_court.txt");
  vector<char> byteData = read_file_bin("text_court.txt", false);
  
  map<char,int> dict_char = count_frequency_char(byteData);
  map<char, int> dict_bit = count_frequency_bit(bitData, 8);

  read_dict(dict_char);
  read_dict(dict_bit);
  return 0;
}