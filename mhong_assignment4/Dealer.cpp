#include "stdafx.h"
#include "Dealer.h"


Dealer::Dealer()
{
}


Dealer::~Dealer()
{
}

//deal 2 cards to the player, showing all of them
void Dealer::dealCard(Player & p)
{
	Card c1 = cd.getCard();
	c1.setVisible(true);
	Card c2 = cd.getCard();
	c2.setVisible(true);

	p.getHand().addCard(c1);
	p.getHand().addCard(c2);
}

//deal 2 cards to the dealer, concealing 1 card
void Dealer::dealCard()
{
	Card c1 = cd.getCard();
	c1.setVisible(true);
	Card c2 = cd.getCard();
	c2.setVisible(false);

	hand.addCard(c1);
	hand.addCard(c2);
}

//pop a card off the card deck. can be used for the dealer or the player
Card Dealer::hit()
{
	return cd.getCard();
}

//at the end of the round, show all the cards
void Dealer::showAllCards()
{
	hand.showAllCards();
}

//at the beginning of a round, clear all the cards
void Dealer::clearHand()
{
	hand.clear();
}
