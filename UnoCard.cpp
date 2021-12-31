/*
 * UnoCard.cpp
 *
 *  Created on: Dec 29, 2021
 *      Author: kabut
 */

#include "UnoCard.hpp"
#include <iostream>
using namespace std;
#include <string>

//Constructor that takes in the cardNumber and the color
UnoCard::UnoCard(int cardNum, string color){
	this->cardNum = cardNum;
	this->color = color;
	prev = NULL;
	next = NULL;
}


//Constructor in case the card has a event, skip, reverse, change color, etc
UnoCard::UnoCard(string color, string event){
	this->color = color;
	this->event = event;
	cardNum = -1;
	prev = NULL;
	next = NULL;
}

//Constructor in this instance a wild card, change color or draw four appears in the pile
UnoCard::UnoCard(string event){
	this->event = event;
	cardNum = -1;
	color = "";
	prev = NULL;
	next = NULL;
}

//Default Constructor
UnoCard::UnoCard() {
	cardNum = -1;
	color = "";
	event = "";
	prev = NULL;
	next = NULL;
}

//Setters for cardNum
void UnoCard::setCardNum(int cardNum){
	this->cardNum = cardNum;
}

//Setters for the color of the card
void UnoCard::setColor(string color){
	this->color = color;
}

//Returns the card number of the uno card
int UnoCard::getCardNum(){
	return cardNum;
}

//Returns the color of the uno card
string UnoCard::getColor(){
	return color;
}


//Gets the event of the card
string UnoCard::getEvent(){
	return event;
}


//To string method to get what card/type the player has
string UnoCard::toString(){
	if(cardNum < 0){
		return "Color is: " + this->getColor() + " and event is: " + this->getEvent();
	}
	else if(event == ""){
		return "Number is: " + this->getCardNum() + " and color is: " + this->getColor();
	}
	else if(cardNum < 0 and color == ""){
		return "Event is: " +  this->getEvent();
	}
}

//Deletes the uno card object
UnoCard::~UnoCard() {
	delete this;
}

