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
	//Player does not have a hand yet
	player->hand = NULL;
	totalCards = 108;
	totalDiscarded = 0;
	string colors[] = {"blue", "red", "green", "yellow"};
	int numbers [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	string events[] = {"skip", "reverse", "drawTwo", "drawFour", "wild"};
	this->totalCards-=7;
	this->hand->cardNum +=7;

}

//Skips the player and check to see if the next's next pointer is not null
UnoPlayer *UnoDeck::skip(UnoPlayer *person){
	UnoPlayer *player = person->prev;
	//Checks to see if there are more than two players
	if(player->next->next != player){
		player = person->next->next;
		return player;
	}
	//In the case there are two players, easy one
	else if(player->next->next == player){
		player->last = player->prev;
		player->last->next = player;
		return player;
	}
	//Else there is only one player which by default is game over
	else{
		return NULL;
	}

}




//Reverses the order of the turn. Need to figure out how the order would be reversed
UnoPlayer *UnoDeck::reverse(UnoPlayer *person){
	UnoPlayer *player = person;
	cout<<"Reversing the order";
	if(player->prev != player){
		bool clockwise = true;
		player = player->prev;
		player->tail = player->next;
	}
	else{
		return NULL;
	}

}


UnoCard *UnoDeck::deal(){
	shuffle();
	UnoCard *card = this->card;
	if(card == NULL){
		return NULL;
	}

	else{
		delete this;
		return card;
		/*while(card != NULL){
			prev = card;
			//In the case of a wild or a drawFour card
			if(card->getCardNum() == -1 && card->color == ""){
				if(card->getEvent() == "drawFour" || card->event == "wild"){
					UnoCard *special = new UnoCard(card->event);
				}
			}
			//Otherwise its a number, color with other events besides drawFour and wild
			else{
				if(card->color != "" && card->cardNum != -1){
					UnoCard *special = new UnoCard(card->cardNum,card->color);
				}
				else if(card->cardNum == -1){
					UnoCard *special = new UnoCard(card->color, card->event);
				}
			}
			card = card->next;
		}
	*/

		//head->next = head;
		//delete head;
		//p

		/*for(int i = 0; i < 7; ++i){
			while(card != NULL){

			}
		}
		*/
	}

}


//Skips the player and check to see if the next's next pointer is not null
/*UnoCard *UnoDeck::skip(){
	UnoCard *card = this->hand;

	//Checks to see if there are players remaining in this case more than two players
	if(card->next->next != NULL){
		card = card->next->next;
	}
	//Checks to see if there are two players left
	else if(card->next->next == card->next){
		card = this;
	}
	//If there is one player left(game would be over by the way)
	else{
		card = NULL;
	}


	return card;
}




//Reverses the turn order
UnoCard *UnoDeck::reverse(){
	UnoCard *card = this->hand;

	//Checks to see if there is only one player
	if(card->prev == NULL && card->next == NULL){
		card = NULL;
	}
	//Else reverse the turn order
	else{
		card = card->prev;
	}

	return card;
}
*/

//Gets the total amount of cards
int UnoDeck::getTotalCards(){
	return this->totalCards;
}


//Gets the total discarded cards in a pile
int UnoDeck::getTotalDiscarded(){
	return this->totalDiscarded;
}

//Shuffles the deck before dealing out the cards
void UnoDeck::shuffle(){
	//Random Distribution of the 108 total cards in the pile
	srand(time(0));
	int shuffle = rand % 108;
	for(int i = 0; i < shuffle; ++i){
		if(hand->getEvent() == "wild" || hand->getEvent() == "drawFour"){
			card = new UnoCard(hand->getEvent());
		}
	}


}

//In case a player has a wild card
void UnoDeck::wild(string color){
	this->hand->setColor(color);

}

//Reshuffles the deck when the totalCards are zero and the pile is full
void UnoDeck::reShuffle(){
	int shuffle = rand % 108;
	if(this->totalCards == 0 && this->totalDiscarded == 108){

	}
}

void UnoDeck::pluckACard(UnoCard *card){
	this->hand->cardNum += 1;
	this->totalCards -=1;

}


//Draws two cards for that player
void UnoDeck::drawTwo(){
	this->hand->cardNum += 2;
	this->totalCards -= 2;
	skip(this->player);
}

void UnoDeck::drawFour(string color){
	this->hand->cardNum += 4;
	this->totalCards -= 4;
	this->hand->setColor(color);
	skip(this->player);
}

//Clears the deck object
UnoDeck::~UnoDeck() {
	delete this->hand;
}

