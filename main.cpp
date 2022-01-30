/*
 * main.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: kabut
 */

#include <iostream>
#include "Uno.hpp"
using namespace std;

int main(){
	int players = 0;
	cout<<"# of players has to be two or more" <<endl;
	cin << players;
	if(players < 2){
		cout<<"Try again"<<endl;
	}
	else{
		//starts the game
	}


	return 0;
}
