#include "Mapper.h"
#include <utility>      // std::pair
#include <iostream>     // std::cout

using namespace std;

void Mapper::initPairing(std::vector<char> a, std::vector<int> r) {
  for(int i=0; i<NUMBER_OF_ALPHABETS; i++) {
    p.insert(std::make_pair(a.at(i), r.at(i)));
    
  }
}
