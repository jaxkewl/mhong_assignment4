// mhong_assignment4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include "GameDisplay.h"
#include "Dealer.h"

int main()
{
	Player p;
	Dealer d;
	Game g(p, d);
	GameDisplay gd(g);
	gd.startGame();

    return 0;
}

