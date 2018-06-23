#include "stdafx.h"
#include "GameDisplay.h"


GameDisplay::GameDisplay(Game g) :game(g)
{
}


GameDisplay::~GameDisplay()
{
}


void GameDisplay::placeBet()
{
	bool goodBet = false;
	while (!goodBet)
	{
		game.clearPlayerBet();
		int playerBet = 0;
		//cout << "Player's current coin count: " << getPlayerCoinBalance() << endl;
		cout << "Place bet?" << endl;
		cin >> playerBet;
		if (playerBet <= game.getPlayer().getPlayerBalance() &&
			playerBet > 0)
		{
			game.getPlayer().setPlayerBalance(playerBet);
			goodBet = true;
		}

	}
}

void GameDisplay::showDealerCards()
{
	Dealer &d = game.getDealer();
	cout << "Dealer Cards:" << endl;
	cout << d.getHand().toString().c_str() << endl;
}

void GameDisplay::showPlayerCards()
{
	cout << "Player Cards:" << endl;
	cout << game.getPlayer().getHand().toString().c_str() << endl;
}


void GameDisplay::promptPlayerAction()
{
	int action = 1;
	while (action == 1)
	{
		cout << "0 to hold, to 1 to hit" << endl;
		cin >> action;
		if (action == 1)
		{
			Card c = game.getDealer().hit();
			game.getPlayer().getHand().addCard(c);
			showPlayerCards();
		}
	}
}

void GameDisplay::endRound()
{
	bool dealerWins = false;
	bool playerWins = false;

	if (game.getPlayer().getHand().getVal > 21)
	{
		cout << "Player busts" << endl;
		dealerWins = true;
		playerWins = false;
	}
	else if (game.getPlayer().getHand().getVal() == 21)
	{
		cout << "Player wins" << endl;
		playerWins = true;
	}
	else
	{
		cout << "Player holds" << endl;
		while (game.getDealer().getHand().getVal() < 17)
		{
			Card c = game.getDealer().hit();
			c.setVisible(true);
			game.getDealer().getHand().addCard(c);
		}
		if (game.getDealer().getHand().getVal() > 21)
		{
			cout << "Dealer busts, player wins" << endl;
			playerWins = true;
			dealerWins = false;
		}
		else if (game.getDealer().getHand().getVal() == 21)
		{
			cout << "Dealer wins" << endl;
			dealerWins = true;
		}
		else
		{
			if (game.getPlayer().getHand().getVal() > game.getDealer().getHand().getVal())
			{
				cout << "Player wins" << endl;
				playerWins = true;
				dealerWins = false;
			}
			else
			{
				cout << "Dealer wins" << endl;
				dealerWins = true;
				playerWins = false;
			}
		}
	}
}


void GameDisplay::startGame()
{
	while (game.getPlayer().getPlayerBalance() > 0)
	{
		placeBet();
		game.getDealer().dealCard();
		game.getDealer().dealCard(game.getPlayer());
		showDealerCards();
		showPlayerCards();
		promptPlayerAction();
	}
}
