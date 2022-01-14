/*
 * UnoDeck.hpp
 *
 *  Created on: Dec 30, 2021
 *      Author: kabut
 */

#ifndef UNODECK_HPP_
#define UNODECK_HPP_
#include <iostream>
#include "UnoCard.hpp"
#include "UnoPlayer.hpp"
using namespace std;

class UnoDeck {
	//Deck for the cards and also includes player
	UnoCard *hand;
	UnoCard *discarded;
	UnoPlayer *player;
	int totalCards;
	UnoCard *card;
	int totalDiscarded;

public:
	UnoDeck();
	UnoDeck(UnoCard *card);
	UnoCard *deal();
	UnoPlayer *skip(UnoPlayer *person);
	UnoPlayer *reverse(UnoPlayer *person);
	void addCard(UnoCard *card);
	void shuffle();
	void reShuffle();
	void wild(string color);
	void pluckACard(UnoCard *card);
	void drawTwo();
	int getTotalCards();
	int getTotalDiscarded();
	void drawFour(string color);
	virtual ~UnoDeck();
};

#endif /* UNODECK_HPP_ */
