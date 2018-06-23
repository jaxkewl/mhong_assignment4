#include "stdafx.h"
#include "GameDisplay.h"


GameDisplay::GameDisplay(Game g) :game(g)
{
}


GameDisplay::~GameDisplay()
{
}


//ask player to place a bet
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
			game.setPlayerBet(playerBet);

			game.getPlayer().setPlayerBalance(game.getPlayer().getPlayerBalance() - playerBet);
			goodBet = true;
		}

	}
}

//show the dealers cards, skipping the one card not visible
void GameDisplay::showDealerCards()
{
	Dealer &d = game.getDealer();
	cout << "Dealer Cards:" << endl;
	cout << d.getHand().toString().c_str() << endl;
}

//display the player's card. all the cards are visible
void GameDisplay::showPlayerCards()
{
	cout << "Player Cards:" << endl;
	cout << game.getPlayer().getHand().toString().c_str() << endl;
	cout << "Value: " << game.getPlayer().getHand().getVal() << endl;
}

//ask player for an action. hit or stay
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

//handle all the display stuff for end of game
void GameDisplay::endRound()
{
	cout << "Player's turn is over" << endl;
	bool dealerWins = false;
	bool playerWins = false;
	game.endRound(dealerWins, playerWins);
	if (dealerWins && playerWins)
	{
		cout << "no one wins" << endl;
	}
	else if (dealerWins)
	{
		cout << "dealer wins" << endl;
	}
	else
	{
		cout << "player wins" << endl;
	}
	showDealerCards();
	cout << "Dealer has: " << game.getDealer().getHand().getVal() << endl;
	cout << "Player balance: " << game.getPlayer().getPlayerBalance() << endl;
}

//the main entry point into the game
//this will repeat until the player has no money.
void GameDisplay::startGame()
{
	while (game.getPlayer().getPlayerBalance() > 0)
	{
		game.startGame();
		cout << "Player Balance: " << game.getPlayer().getPlayerBalance() << endl;
		placeBet();
		game.getDealer().dealCard();
		game.getDealer().dealCard(game.getPlayer());
		showDealerCards();
		showPlayerCards();
		promptPlayerAction();
		endRound();
	}
}
