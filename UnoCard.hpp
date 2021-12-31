/*
 * UnoCard.hpp
 *
 *  Created on: Dec 29, 2021
 *      Author: kabut
 */

#ifndef UNOCARD_HPP_
#define UNOCARD_HPP_

#include <iostream>
using namespace std;

class UnoCard {
	friend class UnoDeck;
	int cardNum;
	string event;
	string color;
	UnoCard *prev;
	UnoCard *next;
public:
	UnoCard(int cardNum, string color);
	UnoCard(string event);
	UnoCard();
	UnoCard(string color, string event);
	int getCardNum();
	string getEvent();
	void setColor(string color);
	void setCardNum(int cardNum);
	void setEvent(string event);
	string getColor();
	string toString();
	virtual ~UnoCard();
};

#endif /* UNOCARD_HPP_ */
