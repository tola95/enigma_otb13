# edit this makefile so that running make compiles your enigma program

enigma: Main.o RotorMachine.o Plugboard.o Rotor.o
	g++ -o enigma Main.o RotorMachine.o Plugboard.o Rotor.o -std=c++11

RotorMachine.o: RotorMachine.cpp
	g++ -c RotorMachine.cpp -std=c++11

Plugboard.o: Plugboard.cpp
	g++ -c Plugboard.cpp -std=c++11

Rotor.o: Rotor.cpp
	g++ -c Rotor.cpp -std=c++11

Main.o: Main.cpp
	g++ -c Main.cpp -std=c++11

clean:
	rm -rf enigma *.o

.PHONY: clean
