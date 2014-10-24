#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include "RotorMachine.h"



  RotorMachine::RotorMachine(int length, std::vector<std::vector<int>>& r) {

    l = length; //Number of rotors in our machine
    ro.resize(l);
    ro = r;
    MakeLinks();
  }

  void RotorMachine::MakeLinks() {

	  std::cout << ro[0].size() << std::endl;
	    for (int i=0; i<l; i++) {
	    	Rotor *rt = new Rotor(ro[i]);
	  		rotors.push_back(*rt);
	  	}
  }

  void RotorMachine::CheckDisplacement() {
	  printf("1\n");
      for (int i=0; i<l-1; i++) {

    	  if(rotors.at(i).getDisplacement() == 0) {
               rotors[i+1].setDisplacement(rotors[i+1].getDisplacement()+1);
    	  }
      }
      printf("2\n");
  }

  std::string RotorMachine::passRotors(std::string s) {
	  std::string str;
	  CheckDisplacement();
      for (int i=0; i<l; i++) {
    	  str = rotors[i].passRotor(s);
    	  s = str;
      }
      return s;
  }

  std::string RotorMachine::passRotorsBack(std::string s) {
	  std::string str;
	  CheckDisplacement();
	  for (int i=l-1; i>=0; i--) {
	      str = rotors[i].passRotorBack(s);
	      s = str;
	  }

	  return s;
  }


