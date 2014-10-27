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

  std::string RotorMachine::passRotors(std::string s) {
	    std::string str;
        for (int i=0; i<l; i++) {
    	    str = rotors[i].passRotor(s);
    	    s = str;
        }
        return s;
    
  }

  std::string RotorMachine::passRotorsBack(std::string s) {
    
	    std::string str;
	    for (int i=l-1; i>=0; i--) {
	        str = rotors[i].passRotorBack(s);
	        s = str;
	    }

	    return s;
    
  }

  void RotorMachine::Rotate() {
    for (int i = 0; i < l; ++i)
    {
      if (i == 0) {
    	  rotors[i].Rotate();
      } else if (rotors[i-1].getDisplacement() == 0) {
    	  rotors[i].Rotate();
      } else {
    	  return ;
      }
    }
  }


