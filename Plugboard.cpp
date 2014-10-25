#include "Plugboard.h"
#include <vector>

#include <iostream>

    Plugboard::Plugboard(std::vector<int>& pBoard) {
    	pb = pBoard;
    }

    //Initialises the plugboard mapping
    void Plugboard::initPairing() {
    	int length = (int) pb.size();
    	for(int i=0; i<length-1; i=i+2) {
    		p.insert(std::make_pair(pb.at(i), pb.at( i + 1)));
    		p.insert(std::make_pair(pb.at( i + 1), pb.at(i)));
    	}
    }

    //Returns the string when passed through the plugboard
	std::string Plugboard::printPlugboard(const std::string &c) {
		initPairing();
        int length = c.length();
        std::string copy;
        copy.resize(length);
        for (int i=0; i<length; i++) {
        	if (p.find(((int) c[i]) - 'A' ) == p.end()) {
        		copy[i] = c[i];
        	} else {
        		copy[i] = (char) ((p.find((int)(c[i] - 'A'))->second) + 'A');
        	}
        }
         return copy;


	}


