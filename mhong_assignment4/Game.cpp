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

//resets the player's bet for a new round
void Game::clearPlayerBet()
{
	setPlayerBet(0);
}

//handle everything that needs to happen when a player holds
//this includes the dealer showing their card and hitting
void Game::endRound(bool & dealerWins, bool & playerWins)
{
	dealer.showAllCards();
	int playerVal = player.getHand().getVal();
	int dealerVal = dealer.getHand().getVal();
	if (playerVal > 21)
	{
		dealerWins = true;
		playerWins = false;
	}
	else if (playerVal == 21)
	{
		playerWins = true;
	}
	else
	{
		while (dealerVal < 17)
		{
			Card c = dealer.hit();
			c.setVisible(true);
			dealer.getHand().addCard(c);
			dealerVal = dealer.getHand().getVal();
		}
		if (dealerVal > 21)
		{
			playerWins = true;
			dealerWins = false;
		}
		else if (dealerVal == 21)
		{
			dealerWins = true;
		}
		else
		{
			if (dealerVal > playerVal)
			{
				playerWins = false;
				dealerWins = true;
			}
			else if (dealerVal < playerVal)
			{
				dealerWins = false;
				playerWins = true;
			}
			else
			{
				dealerWins = true;
				playerWins = true;
			}
		}
	}

	if (playerWins && !dealerWins)
	{
		int bal = 2 * (getPlayerBet());
		cout << "Player wins " << bal << endl;
		player.setPlayerBalance(bal + player.getPlayerBalance());
	}
	else if (!playerWins && dealerWins)
	{
		//do nothing since money was already taken
	}
	else
	{
		int bal = player.getPlayerBalance() + getPlayerBet();
		player.setPlayerBalance(bal);
	}
}

//all the things need to initialize when starting a game, for now its just
//clearing the hands from the dealer and player
void Game::startGame()
{
	player.clearHand();
	dealer.clearHand();
}


