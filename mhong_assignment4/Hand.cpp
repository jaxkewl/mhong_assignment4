#include "stdafx.h"
#include "Hand.h"


Hand::Hand()
{
}


Hand::~Hand()
{
}

string Hand::toString()
{
	string ret;

	for (auto c = cards.begin(); c != cards.end(); ++c)
	{
		ret.append(c->toString());
	}
	return ret;
}

//add a card to the hand
void Hand::addCard(Card & c)
{
	cards.push_back(c);
}

//get the numerical value of a hand if playing black jack
int Hand::getVal()
{
	int total = 0;
	for (auto c = cards.begin(); c != cards.end(); ++c)
	{
		total += cardToIntMap1[c->getVal()];
	}

	if (total > 21)
	{
		total = 0;
		for (auto c = cards.begin(); c != cards.end(); ++c)
		{
			total += cardToIntMap2[c->getVal()];
		}
	}
	return total;
}

//make all the cards visible
void Hand::showAllCards()
{
	for (auto c = cards.begin(); c != cards.end(); ++c)
	{
		c->setVisible(true);
	}
}

//clear the cards
void Hand::clear()
{
	cards.clear();
}
