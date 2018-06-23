#pragma once
#include "Hand.h"
class Player
{
public:
	Player();
	~Player();

	int getPlayerBalance() const { return playerBalance; }
	void setPlayerBalance(int val) { playerBalance = val; }
	Hand& getHand() { return hand; }
	void setHand(Hand val) { hand = val; }
	void clearHand();
private:
	int playerBalance = 100;
	Hand hand;

};

