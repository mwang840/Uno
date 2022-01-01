/*
 * UnoPlayer.hpp
 *
 *  Created on: Dec 30, 2021
 *      Author: kabut
 */

#ifndef UNOPLAYER_HPP_
#define UNOPLAYER_HPP_
#include <iostream>
#include <time.h>

using namespace std;


class UnoPlayer {
	string playerName;
public:
	UnoPlayer(string playerName);
	virtual ~UnoPlayer();
};

#endif /* UNOPLAYER_HPP_ */
