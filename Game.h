#include <string>
#include <algorithm>
#include "Suit.h"
#include "Player.h"
#include "Card.h"
#include <time.h>
#include<iostream>
#include<deque>
class Game
{
	std::deque<Card*> deck;
	Player player;
	Player house;

public:
	Game();
	~Game()=default;
	void fillDeck();
	void gameRules();
	char choice{ 'y'};
	int turn = 0;
};

