#ifndef ROTORMACHINE_H
#define ROTORMACHINE_H
#include "vector"
#include "map"
#include "Rotor.h"

class RotorMachine {

private:
	std::vector<Rotor> rotors;
	int l;
	std::vector<std::vector<int>> ro;

public:
	RotorMachine(int length, std::vector<std::vector<int>>& r);

	void MakeLinks();


	std::string passRotors(std::string s);

	std::string passRotorsBack(std::string s);

	void Rotate();
};
#endif
