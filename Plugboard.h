#ifndef PLUGBOARD_H
#define PLUGBOARD_H
#include <map>
#include <vector>

class Plugboard {
private:
	std::vector<int> pb;
	std::map<int, int> p;

public:
	Plugboard(std::vector<int>& pBoard);

 void initPairing();

 std::string printPlugboard( const std::string &c);
};
#endif
