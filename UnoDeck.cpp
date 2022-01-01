/*
 * UnoDeck.cpp
 *
 *  Created on: Dec 30, 2021
 *      Author: kabut
 */

#include "UnoDeck.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

//Takes in account the whole uno pile
UnoDeck::UnoDeck() {
	string colors[] = {"blue", "red", "green", "yellow"};
	int numbers [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	string events[] = {"skip", "reverse", "drawTwo", "drawFour", "wild"};
	/*for(int i = 0; i < sizeof(numbers); ++i){

	}

	*/

	this->totalCards-=7;
	this->hand->cardNum +=7;
}

//Skips the player and check to see if the next's next pointer is not null
UnoCard *UnoDeck::skip(){
	UnoCard *card = this->hand;

	//Checks to see if there are players remaining in this case more than two players
	if(card->next->next != NULL){
		card = card->next->next;
	}
	//Checks to see if there are two players left
	else if(card->next->next == NULL){
		card = this;
	}
	//If there is one player left(game would be over by the way)
	else{
		card = NULL;
	}


	return card;
}

//Gets the total amount of cards
int UnoDeck::getTotalCards(){
	return this->totalCards;
}


//Gets the total discarded cards in a pile
int UnoDeck::getTotalDiscarded(){
	return this->totalDiscarded;
}


void UnoDeck::shuffle(){

}


void UnoDeck::wild(string color){
	this->hand->setColor(color);
}

//Reshuffles the deck when the totalCards are zero
void UnoDeck::reShuffle(){

}


//Draws two cards for that player
void UnoDeck::drawTwo(){
	this->hand->cardNum += 2;
	this->totalCards -= 2;
	skip();
}

void UnoDeck::drawFour(string color){
	this->hand->cardNum += 4;
	this->totalCards -= 4;
	this->hand->setColor(color);
	skip();
}

//Clears the deck object
UnoDeck::~UnoDeck() {
	delete this->hand;
}

