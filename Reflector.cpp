#include "Reflector.h"

using namespace std;

char Reflection(char* c) {
  int in = (int) *c;
  int x = in - 255;
  int ou = (x + 13) % 26;
  int y = ou + 255;
  char d = (char) y;
  char* p;
  p = d;
  return p; 
}
