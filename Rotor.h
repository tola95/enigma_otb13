#ifndef ROTOR_H
#define ROTOR_H
#include "vector"
#include "map"

class Rotor {
private:
	std::vector<int> ro;
	std::map<char, int> p;
	int displacement;
	Rotor *previous;
	Rotor *next;

public:
	int NUMBER_OF_ALPHABETS =26;

	void initMap();

    void copy(char c);

	Rotor(std::vector<int>& r);

	std::string passRotor(std::string& s);

	int getDisplacement();

    void setDisplacement(int i);

    std::string passRotorBack(std::string& s);

    std::map<int, char> flippedMap();

    void Rotate();
};

#endif
