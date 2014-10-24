// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
#include "Plugboard.h"
#include "Rotor.h"
#include "RotorMachine.h"
#include "Reflector.h"

using namespace std;

int main(int argc, char **argv)
{ 
    int noOfRotors = argc-2;

	//Read the contents of the last file (the plugboard) and put in a vector
	std::ifstream f;
	std::vector<int> pb;
	f.open(argv[argc - 1]);
	int x;
	while(f >> x >> std::ws) {
	    pb.push_back(x);
	}

  std::vector<std::vector<int>> vecOfRotors;
  vecOfRotors.resize(noOfRotors);
  if (argc > 2) {
  //Read the contents of the rotors and put them in the vector of vectors of ints
    printf("vecOfRotors");
	for (int i=1; i< argc - 1; i++) {
		std::ifstream fs;
		fs.open(argv[i]);
		int y;
		while(fs >> y >> std::ws) {
			vecOfRotors[i-1].push_back(y);
		}
	}
	printf("\n");
  }

  //I-O instructions on the command line
  char c;
  cout << "Press E to encrypt, D to decrypt: " << endl;
  cin >> c;
  Plugboard *pboard = new Plugboard(pb);
  RotorMachine *rotorM = new RotorMachine(noOfRotors, vecOfRotors);

  if (c == 'E') {
    cout << "Please input your message to be encrypted: " << endl;
    std::string msg;
    cin >> msg;
    std::string soln = pboard->printPlugboard(rotorM->passRotorsBack(Reflection(rotorM->passRotors(pboard->printPlugboard(msg)))));
    cout << soln << endl;
  } else if (c == 'D') {
    cout << "Please input your message to be decrypted: " << endl;
    std::string msg;
    cin >> msg;
    std::string soln;
 //   soln = Decrypt(msg); 
    cout << soln << endl;
  } else {
    exit(EXIT_FAILURE);
  } 
  
  return 1;
}
