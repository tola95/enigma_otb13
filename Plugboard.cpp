#include "Mapper.h"
#include "Plugboard.h"

using namespace std;

    std::map<int, int> p;

    void Plugboard::initPairing(std::vector<int> pb) {
    	int length = pb.size()/sizeof(char);
    	for(int i=0; i<length; i+2) {
    		p.insert(std::make_pair(pb.at(i), pb.at(i+1)));
    	}
    }

	std::string Plugboard::Plugboard(std::vector<int> pb, const std::string &c) {
		Plugboard::initPairing(pb);
        int length = c.length()/sizeof(char);
        std::string copy;
        for (int i=0; i<length; i++) {
        	if (p.find(c[i])->first == ((int) c - 255)) {
        		copy[i] = p.find(c[i])->second;
        	} else {
        		copy[i] = c[i];
        	}
        }
         return copy;

	}


