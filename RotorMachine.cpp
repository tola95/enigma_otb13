#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include "RotorMachine.h"



  RotorMachine::RotorMachine(int length, std::vector<std::vector<int>>& r) {
    l = length; //Number of rotors in our machine
    ro = r;
    RotorMachine::MakeLinks();
  }

  void RotorMachine::MakeLinks() {

	    Rotor* rPtr;

	    for (int i=0; i<l; i++) {
	  		rotors.push_back(*(new Rotor(ro[i])));
	  	}

		for (int i=0; i<l-1; i++) {
			rPtr = &(rotors.at(i+1));
			rotors.at(i).setNext(rPtr);
		}

		for (int i=l-1; i>0; i--) {
			rPtr = &(rotors.at(i-1));
			rotors.at(i).setPrevious(rPtr);
		}

		//free(rPtr);
  }

  void RotorMachine::CheckDisplacement() {
      for (int i=0; i<l-1; i++) {
    	  if(rotors.at(i).getDisplacement() == 0) {
               rotors.at(i+1).setDisplacement(rotors.at(i+1).getDisplacement()+1);
    	  }
      }
  }


