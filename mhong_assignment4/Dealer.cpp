#include "stdafx.h"
#include "Dealer.h"


Dealer::Dealer()
{
}


Dealer::~Dealer()
{
}

void Dealer::dealCard(Player & p)
{
	Card c1 = cd.getCard();
	c1.setVisible(true);
	Card c2 = cd.getCard();
	c2.setVisible(true);

	p.getHand().addCard(c1);
	p.getHand().addCard(c2);
}

void Dealer::dealCard()
{
	Card c1 = cd.getCard();
	c1.setVisible(true);
	Card c2 = cd.getCard();
	c2.setVisible(false);

	hand.addCard(c1);
	hand.addCard(c2);
}

Card Dealer::hit()
{
	return cd.getCard();
}
