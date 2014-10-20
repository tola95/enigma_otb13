#ifndef ROTOR_H
#define ROTOR_H
#include "vector"
#include "map"

class Rotor {
private:
	//std::vector<std::vector<int>> rotors;
	std::vector<int> ro;
	std::map<char, int> p;
	int displacement;
	Rotor *previous;
	Rotor *next;

public:
	int NUMBER_OF_ALPHABETS =26;

	void initMap();

	Rotor(std::vector<int> r);

	std::string passRotor(std::string s);

	Rotor* getPrevious();

	void setPrevious(Rotor *r);

	Rotor* getNext();

	void setNext(Rotor *r);

	int getDisplacement();

    void setDisplacement(int i);

    std::map<char, int> getMap();

    std::string passRotorBack(std::string s);

    std::map<int, char> flippedMap();

    //void Rotate();
};

#endif
