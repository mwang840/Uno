/*
 * Uno.cpp
 *
 *  Created on: Dec 29, 2021
 *      Author: kabut
 */

#include "Uno.hpp"
#include"UnoPlayer.hpp"
#include <iostream>

using namespace std;



Uno::Uno() {
	string person;
	std::cout<<"Name of this player"<<endl;
	cin<< person;
	player = new UnoPlayer(person);
	this->hand = new UnoDeck();

}

void Uno::startGame(){
	hand->shuffle();

}

Uno::~Uno() {
	// TODO Auto-generated destructor stub
}

