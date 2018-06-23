#pragma once
#include <list>
#include "Card.h"

using namespace std;
class Hand
{
public:
	Hand();
	~Hand();
	string toString();
	void addCard(Card & c);
	int getVal();
	void showAllCards();
	void clear();
private:
	list<Card> cards;
	int pointVal = 0;
	map<Card::VAL, int> cardToIntMap1 = {
		{ Card::TWO, 2 },
		{ Card::THREE, 3 },
		{ Card::FOUR, 4 },
		{ Card::FIVE, 5 },
		{ Card::SIX, 6 },
		{ Card::SEVEN, 7 },
		{ Card::EIGHT, 8 },
		{ Card::NINE, 9 },
		{ Card::TEN, 10 },
		{ Card::JACK, 10 },
		{ Card::QUEEN, 10 },
		{ Card::KING, 10 },
		{ Card::ACE, 11 }
	};
	map<Card::VAL, int> cardToIntMap2 = {
		{ Card::TWO, 2 },
		{ Card::THREE, 3 },
		{ Card::FOUR, 4 },
		{ Card::FIVE, 5 },
		{ Card::SIX, 6 },
		{ Card::SEVEN, 7 },
		{ Card::EIGHT, 8 },
		{ Card::NINE, 9 },
		{ Card::TEN, 10 },
		{ Card::JACK, 10 },
		{ Card::QUEEN, 10 },
		{ Card::KING, 10 },
		{ Card::ACE, 1 }
	};
};

