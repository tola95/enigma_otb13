#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include "RotorMachine.h"



  RotorMachine::RotorMachine(int length, std::vector<std::vector<int>> r) {
    l = length; //Number of rotors in our machine
    ro = r;
    RotorMachine::MakeLinks();
  }

  void RotorMachine::MakeLinks() {

	    for (int i=0; i<l; i++) {
	  		rotors.at(i) = new Rotor(ro.at(i));
	  	}

		for (int i=0; i<l-1; i++) {
			rotors.at(i).setNext(rotors.at(i+1));
		}

		for (int i=l-1; i>0; i++) {
			rotors.at(i).setPrevious(rotors.at(i-1));
		}
  }

  void RotorMachine::CheckDisplacement() {
      for (int i=0; i<l-1; i++) {
    	  if(rotors.at(i).getDisplacement() == 0) {
               rotors.at(i+1).getDisplacement()++;
    	  }
      }
  }


