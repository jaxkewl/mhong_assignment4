#pragma once

#include <iostream>
#include "Game.h"

using namespace std;

class GameDisplay
{
public:
	GameDisplay(Game g);
	~GameDisplay();
	void startGame();

private:
	void placeBet();
	void showDealerCards();
	void showPlayerCards();
	Game game;
	void promptPlayerAction();
	void endRound();
};

