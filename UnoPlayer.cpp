/*
 * UnoPlayer.cpp
 *
 *  Created on: Dec 30, 2021
 *      Author: kabut
 */

#include "UnoPlayer.hpp"
#include "UnoDeck.hpp"
#include <iostream>
using namespace std;

//Constructor for the player
UnoPlayer::UnoPlayer(string playerName) {
	this->playerName = playerName;
	this->hand = NULL;
	next = NULL;
	last = NULL;
	prev = NULL;
	tail = prev;
}

//Gets the deck of this player
UnoDeck *UnoPlayer::getDeck(){
	return hand;
}

UnoPlayer::~UnoPlayer() {
	this->playerName = "";
	delete this;
}

