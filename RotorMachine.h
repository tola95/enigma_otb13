#ifndef ROTORMACHINE_H
#define ROTORMACHINE_H
#include "vector"
#include "map"

class RotorMachine {

private:
	std::vector<Rotor> rotors;
	int l;
	std::vector<std::vector<int>> ro;

public:
	RotorMachine::RotorMachine(int length, std::vector<std::vector<int>> r);

	void RotorMachine::MakeLinks();

	void RotorMachine::CheckDisplacement();
};
#endif
