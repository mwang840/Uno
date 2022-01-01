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
using namespace std;

class UnoDeck {
	//Deck for the cards
	UnoCard *hand;
	UnoCard *discarded;
	int totalCards = 108;
	int totalDiscarded = 0;
public:
	UnoDeck();
	UnoDeck(UnoCard *card);
	UnoCard *deal();
	UnoCard *skip();
	UnoCard *reverse();
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
