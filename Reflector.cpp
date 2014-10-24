#include "Reflector.h"
#include <string>


std::string Reflection(std::string s) {
  std::string copy;
  copy.resize(s.length());
  for (int i=0; i<s.length(); i++) {
	  copy[i] = ((s[i] - 'A' + 13) % 26) + 'A';
  }
  return copy;
}
