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
/*
      for (int i = 0; i < l-1; ++i)
      {
        rotors[i].setNext(&rotors[i+1]);
      }

      

      for (int i = l-1; i > 0; ++i)
      {
        rotors[i].setPrevious(&rotors[i-1]);
      }

      if (l>0) {
         rotors[l-1].setNext(NULL);
         rotors[0].setPrevious(NULL);
      }
 */

  }

  void RotorMachine::CheckDisplacement() {
      for (int i=0; i<l-1; i++) {

    	  if(rotors.at(i).getDisplacement() == 0) {
               rotors[i+1].setDisplacement(rotors[i+1].getDisplacement()+1);
    	  }
      }
  }

  std::string RotorMachine::passRotors(std::string s) {
	    std::string str;
	    CheckDisplacement();
      //Rotate(s);
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
	        RotorMachine::Rotate();
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


