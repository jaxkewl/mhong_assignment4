#include <map>
#include "CardDeck.h"
#include "Player.h"
#include "Dealer.h"

using namespace std;

#pragma once
class Game
{
public:
	Game(Player p, Dealer d);
	Game();
	~Game();
	void clearPlayerBet();
	Player& getPlayer() { return player; }
	void setPlayer(Player val) { player = val; }
	Dealer & getDealer() { return dealer; }
	void setDealer(Dealer val) { dealer = val; }
	void endRound(bool & dealerWins, bool & playerWins);
	int getPlayerBet() const { return playerBet; }
	void setPlayerBet(int val) { playerBet = val; }
	void startGame();

private:
	int playerBet = 0;
	Player player;
	Dealer dealer;

};

