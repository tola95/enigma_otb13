#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include "Rotor.h"
#include <stdlib.h>
#include <stdio.h>

 Rotor::Rotor(std::vector<int>& r) {
	 ro = r;
     initMap();
	 setDisplacement(0);
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

 //Initialise Rotor mapping
 void Rotor::initMap(){
	 for(int i=0; i<26; i++) {
	     p.insert(std::make_pair((char)(i + 'A'), ro.at(i)));
	 }
 }

 //Returns current displacement of rotor
 int Rotor::getDisplacement() {
	 return displacement % 26;
 }

 //Sets current displacement of rotor
 void Rotor::setDisplacement(int i) {
	 displacement = i;
 }

 //Returns string after it has been processed by the rotor
 std::string Rotor::passRotor(std::string& s) {
     std::string copy;
     copy.resize(s.length());

     for(int i=0; i<s.length(); i++) {

    	 int newc = ((s[i] - 'A') + getDisplacement());
    	 if (newc >= 26) {
    		 newc = (newc % 26);
    	 }
    	 int value = (((p.at((newc + 'A')) - getDisplacement() ) + 26) % 26) + 'A';
    	 //if (value < 65) {
    	 //	 value = 90 - ('A' - value) ;
    	 //}
    	 std::cout << value << std::endl;
    	 copy[i] = value;
     }

     return copy;
 }

 //Returns string after it has been processed
 //by the rotor in the opposite direction
 std::string Rotor::passRotorBack(std::string& s){
	 std::map<int, char> reversed = flippedMap();
	 std::string copy;
	 copy.resize(s.length());
	 for(int i=0; i<s.length(); i++) {
		 //std::cout << s[i] << std::endl;
		 //printf("Gives\n");

    	 int newc = (s[i] + getDisplacement()) - 'A';
    	 if (newc >= 26) {
    		 newc = (newc % (26)) ;
    	 }
    	 int value = (reversed.find(newc)->second - 'A') - getDisplacement();
    	 value = ((value + 26) % (26)) + 'A';
    	 copy[i] = value ;

    	 std::cout << copy[i] << std::endl;
	 }

	 return copy;
 }

 //Returns the map of the current rotor, with keys and values flipped
 std::map<int, char> Rotor::flippedMap() {
	 std::map<int, char> reversed;
	 for (int i=0; i<26; i++) {
	     reversed.insert(std::make_pair(
	    		 p.find('A'+ i)->second ,
	             p.find('A'+ i)->first
	     ));
	 }
	 return reversed;
 }

 void Rotor::Rotate() {
   displacement++;
   displacement %= 26;
 }

