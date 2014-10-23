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

	    for (int i=0; i<l; i++) {
	    	Rotor *rt = new Rotor(ro[i]);
	  		rotors.push_back(*rt);
	  	}

  }

  void RotorMachine::CheckDisplacement() {
      for (int i=0; i<l-1; i++) {
    	  if(rotors.at(i).getDisplacement() == 0) {
               rotors.at(i+1).setDisplacement(rotors.at(i+1).getDisplacement()+1);
    	  }
      }
  }
/*
  std::string RotorMachine::passRotors(std::string s) {
	  std::string str;
      for (int i=0; i<l; i++) {
    	  str = rotors[i].passRotor(s);
    	  s = str;
      }
      return s;
  }
*/

