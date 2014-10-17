// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <boost/tokenizer.hpp>
#include <string>
#include <boost/foreach.hpp>
#include <vector>
#include "Plugboard.h"

using namespace std;
using namespace boost;


int main(int argc, char **argv)
{ 

	//Read the contents of the first file (the plugboard), sending the ints to the vector in struct utils
	std::fstream f;
	std::string line;
	ifstream pbFile("argv[1]");
	std::vector<int> pb;
	int num = 0;

	while(std::getline(pbFile, line)) {
		pbFile >> pb.at(num);

	}


  std::fstream fs;
  if (argc > 1) {
    //Open the command line argument files for reading
    for(int i=2; i<argc; i++) {
      if (argv[i] == NULL){
        perror( " Error: Could not open file. \n" );
        exit(EXIT_FAILURE);
     }
      fs.open("argv[i]", std::fstream::in);

      //Tokenise each line of file, putting the ints into vector v
      
    }
  } 

  //I-O instructions on the command line
  char c;
  cout << "Press E to encrypt, D to decrypt: " << endl;
  cin >> c;

  if (c == 'E') {
    cout << "Please input your message to be encrypted: " << endl;
    std::string msg;
    cin >> msg;
    std::basic_string<char> soln;
    std::basic_string<char> soln1 = Plugboard(pb, soln);
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
  
  
}
