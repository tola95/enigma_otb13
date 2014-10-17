#ifndef MAPPER_H
#define MAPPER_H
#include <vector>
#include <map>

class Mapper {

const int NUMBER_OF_ALPHABETS = 26;
std::map<char, int> p;
std::vector<char> alphabet; 


public:
void initAlphabet() {
  for(int i=0; i< NUMBER_OF_ALPHABETS; i++) {
    alphabet.push_back((char) (i+(int) 'A') );
  }
}

void initPairing(std::vector<int> r);

};
#endif
