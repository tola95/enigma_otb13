#include "Plugboard.h"
#include <vector>

    Plugboard::Plugboard(std::vector<int>& pBoard) {
    	pb = pBoard;
    }

    void Plugboard::initPairing() {
    	int length = pb.size()/sizeof(int);
    	for(int i=0; i<length; i+2) {
    		p.insert(std::make_pair(pb.at(i), pb.at(i+1)));
    	}
    }

	std::string Plugboard::printPlugboard(const std::string &c) {
		Plugboard::initPairing();
        int length = c.length()/sizeof(char);
        std::string copy;
        for (int i=0; i<length; i++) {
        	if (p.find((int) c[i])->first == ((int) c[i] - 255)) {
        		copy[i] = (char) p.find(c[i])->second;
        	} else {
        		copy[i] = c[i];
        	}
        }
         return copy;

	}


