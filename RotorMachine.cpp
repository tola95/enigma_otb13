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

      for (int i = 0; i < l-1; ++i)
      {
        rotors[i].setNext(&rotors[i+1]);
      }

      for (int i = l-1; i > 0; ++i)
      {
        rotors[i].setPrevious(&rotors[i-1]);
      }

  }

  void RotorMachine::CheckDisplacement() {
      for (int i=0; i<l-1; i++) {

    	  if(rotors.at(i).getDisplacement() == 0) {
               rotors[i+1].setDisplacement(rotors[i+1].getDisplacement()+1);
    	  }
      }
  }

  std::string RotorMachine::passRotors(std::string s) {
    if (l == 0) {
      return s;
    } else {
	    std::string str;
	    CheckDisplacement();
      //Rotate(s);
        for (int i=0; i<l; i++) {
    	    str = rotors[i].passRotor(s);
    	    s = str;
        }
        return s;
    }
  }

  std::string RotorMachine::passRotorsBack(std::string s) {
    if (l == 0) {
      return s;
    } else {
	    std::string str;
	    CheckDisplacement();
	    for (int i=l-1; i>=0; i--) {
	        str = rotors[i].passRotorBack(s);
	        s = str;
	    }

	    return s;
    }
  }
/*
  void Rotate(std::string s) {
    for (int i = 0; i < s.length(); ++i)
    {
      rotors[s.length() / 26].setDisplacement()
    }
  }
*/

