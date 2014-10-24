#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include "Rotor.h"
#include <stdlib.h>
#include <stdio.h>

 Rotor::Rotor(std::vector<int>& r) {
	 printf("5");
	 ro = r;
     initMap();
	 setDisplacement(0);
	 printf("Rotor initialised");
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
	     p.insert(std::make_pair((char)(i + 'A'), ro.at(i)));
	 }
	 printf("B is mapped to ");
	 std::cout << p.find('B')->second << std::endl;
 }

 int Rotor::getDisplacement() {
	 return displacement % 26;
 }

 void Rotor::setDisplacement(int i) {
	 displacement = i;
 }


 std::string Rotor::passRotor(std::string& s) {
     std::string copy;
     copy.resize(s.length());

     for(int i=0; i<s.length(); i++) {

    	 int newc = (s[i] + getDisplacement());
    	 if (newc > 'Z') {
    		 newc = (newc % 'Z') + 'A';
    	 }
    	 int value = (p.at((newc)) - getDisplacement() ) + 'A';
    	 if (value < 65) {
    		 value = 90 - ('A' - value) ;
    	 }
    	 copy[i] = value;
     }
     displacement++;
     std::cout << copy << std::endl;
     return copy;
 }

 std::map<char, int> Rotor::getMap() {
	 return p;
 }

 std::string Rotor::passRotorBack(std::string& s){
	 std::map<int, char> reversed = flippedMap();
	 std::string copy;
	 copy.resize(s.length());
	 for(int i=0; i<s.length(); i++) {

    	 int newc = (s[i] + getDisplacement()) - 'A';
    	 if (newc > 'Z' - 'A') {
    		 newc = (newc % 'Z' - 'A') ;
    	 }
    	 int value = reversed.find(newc)->second - getDisplacement();
    	 value = (value + 'Z' -'A') % ('Z' - 'A');
    	 copy[i] = value + 'A';
	 }
	 return copy;
 }

 std::map<int, char> Rotor::flippedMap() {
	 std::map<int, char> reversed;
	 for (int i=0; i<26; i++) {
	     reversed.insert(std::make_pair(p.find('A'+ i)->second ,p.find('A'+ i)->first)) ;
	 }
	 return reversed;
 }

 //void Rotate() {

 //}

