#include "stdafx.h"
#include "Player.h"


//constructor
Player::Player() :playerBalance(100)
{
}


Player::~Player()
{
}

//clear the cards
void Player::clearHand()
{
	hand.clear();
}
