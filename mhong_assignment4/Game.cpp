#include "stdafx.h"
#include "Game.h"


Game::Game(Player p, Dealer d) :player(p), dealer(d)
{
}

Game::Game()
{
}


Game::~Game()
{
}

void Game::clearPlayerBet()
{
	playerBet = 0;
}


