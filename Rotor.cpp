#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include "Rotor.h"


 Rotor::Rotor(std::vector<int>& r) {
     initMap();
	 setDisplacement(0);
	 ro = r;
 }

 Rotor* Rotor::getPrevious() {
     return previous;
 }

 void Rotor::setPrevious(Rotor *r) {
	 previous = r;
 }

 Rotor* Rotor::getNext() {
	 return next;
 }

 void Rotor::setNext(Rotor *r) {
	 next = r;
 }

 void Rotor::initMap(){
	 for(int i=0; i<26; i++) {
	     p.insert(std::make_pair((char)(i + 255), ro.at(i)));
	 }
 }

 int Rotor::getDisplacement() {
	 return displacement % 26;
 }

 void Rotor::setDisplacement(int i) {
	 displacement = i;
 }

 std::string Rotor::passRotor(std::string& s) {
     std::string copy;
     int strlen = s.length()/sizeof(char);
     for(int i=0; i<strlen; i++) {
    	 copy[i] = (char) (p.find(((int) copy[i] - 255)
    	           + getDisplacement())->second - getDisplacement());
     }
     displacement++;
     return copy;
 }

 std::map<char, int> Rotor::getMap() {
	 return p;
 }

 std::string Rotor::passRotorBack(std::string& s){
	 std::map<int, char> reversed = flippedMap();
	 std::string copy;
	 int strlen = s.length()/sizeof(char);
	 for(int i=0; i<strlen; i++) {
		 copy[i] = (char) (reversed.find(((int) copy[i] - 255)
				   - getDisplacement())->second + getDisplacement());
	 }
	 return copy;
 }

 std::map<int, char> Rotor::flippedMap() {
	 std::map<int, char> reversed;
	 for (int i=0; i<26; i++) {
	     reversed.find(i)->second = p.find(i)->first;
	 }
	 return reversed;
 }

 //void Rotate() {

 //}

