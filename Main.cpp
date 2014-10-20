// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include "Plugboard.h"
#include "Rotor.h"
#include "RotorMachine.h"

using namespace std;



int main(int argc, char **argv)
{ 

	//Read the contents of the first file (the plugboard) and put in a vector
	std::fstream f;
	char * line = (char*) malloc(26*sizeof(int));
	ifstream pbFile("argv[argc-1]");
	std::vector<int> pb;
	int num = 0;

	f.open("argv[argc - 1]", std::fstream::in);

	pbFile >> line;

	char * ch;
	ch = strtok(line, " ");
	while (ch != NULL){
	  pb.push_back(atoi(ch));
	  printf ("%s\n", ch);
	  ch = strtok (NULL, "");
    }


  std::fstream fs;
  std::vector<std::vector<int>> vecOfRotors;
  if (argc > 1) {
    //Open the command line argument files for reading. arg[2] and afterwards will be rotors
    for(int i=1; i<argc-1; i++) {
      if (argv[i] == NULL){
        perror( " Error: Could not open file. \n" );
        exit(EXIT_FAILURE);
     }
      fs.open("argv[i]", std::fstream::in);
      ifstream rFile("argv[i]");
      
      rFile >> line;

      ch = strtok(line, " ");
      while (ch !=NULL) {
    	  vecOfRotors.at(i-1).push_back(atoi(ch));
    	  printf ("%s\n", ch);
    	  ch = strtok (NULL, "");
      }
    }
  } 

  //I-O instructions on the command line
  char c;
  cout << "Press E to encrypt, D to decrypt: " << endl;
  cin >> c;
  Plugboard *pboard = new Plugboard(pb);
  Rotor *rotor = new RotorMachine(vecOfRotors);

  if (c == 'E') {
    cout << "Please input your message to be encrypted: " << endl;
    std::string msg;
    cin >> msg;
    std::string soln;
    std::string soln1 = pboard->printPlugboard(soln);
    cout << soln1 << endl;
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
  
  free(line);
  
}
