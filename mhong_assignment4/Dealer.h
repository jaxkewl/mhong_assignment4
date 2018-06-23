#pragma once
#include "Hand.h"
#include "Player.h"
#include "CardDeck.h"

class Dealer
{
public:
	Dealer();
	~Dealer();

	Hand& getHand() { return hand; }
	void setHand(Hand val) { hand = val; }
	void dealCard(Player & p);
	void dealCard();
	Card hit();
	void showAllCards();
	void clearHand();

private:
	Hand hand;
	CardDeck cd;
};

