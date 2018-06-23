#include "stdafx.h"
#include "Card.h"

Card::Card(SUIT suit, VAL val) : suit(suit), val(val)
{
}

Card::~Card()
{
}

//get a string representation of the card
string Card::toString()
{
	if (getVisible())
	{
		string ret = valMap[getVal()];
		ret.append(" of ");
		ret.append(suitMap[getSuit()]);
		ret.append("\n");
		return ret;
	}
	else
	{
		return "Card is not visible";
	}
}
