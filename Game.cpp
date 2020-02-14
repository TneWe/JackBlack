#include "Game.h"

Game::Game()
{
	fillDeck();
	gameRules();

}

void Game::fillDeck()
{
	srand(time(NULL));

	for (int i = 2; i <= 14; i++)
	{
		if (i == 14)
		{
			deck.push_back(new Card("As", 11, Suit::Hearts));
			deck.push_back(new Card("As", 11, Suit::Spades));
			deck.push_back(new Card("As", 11, Suit::Diamonds));
			deck.push_back(new Card("As", 11, Suit::Clubs));
		}
		if (i == 13)
		{
			deck.push_back(new Card("Kralj", 10, Suit::Hearts));
			deck.push_back(new Card("Kralj", 10, Suit::Spades));
			deck.push_back(new Card("Kralj", 10, Suit::Diamonds));
			deck.push_back(new Card("Kralj", 10, Suit::Clubs));
		}
		if (i == 12)
		{
			deck.push_back(new Card("Cura", 10, Suit::Hearts));
			deck.push_back(new Card("Cura", 10, Suit::Spades));
			deck.push_back(new Card("Cura", 10, Suit::Diamonds));
			deck.push_back(new Card("Cura", 10, Suit::Clubs));
		}
		if (i == 11)
		{
			deck.push_back(new Card("Decko", 10, Suit::Hearts));
			deck.push_back(new Card("Decko", 10, Suit::Spades));
			deck.push_back(new Card("Decko", 10, Suit::Diamonds));
			deck.push_back(new Card("Decko", 10, Suit::Clubs));
		}
		if (i <= 10)
		{
			deck.push_back(new Card("Broj", i, Suit::Hearts));
			deck.push_back(new Card("Broj", i, Suit::Spades));
			deck.push_back(new Card("Broj", i, Suit::Diamonds));
			deck.push_back(new Card("Broj", i, Suit::Clubs));
		}
	}

	std::random_shuffle(deck.begin(), deck.end());
}
void Game::gameRules()
{
	while (choice == 'y')
	{
		player.addObj(*deck[deck.size() - 1]);
		deck.pop_back();
		if (player.getHandValue(turn) == 11 && turn > 0 && player.previousValue() >= 11)
		{
			player.changeValue(1, turn);
		}
		++turn;
		if (house.pValue() < 17 && turn == 1)
		{
			house.addObj(*deck[deck.size() - 1]);
			deck.pop_back();
		}
		if (house.pValue() < 17 && turn >= 3)
		{
			house.addObj(*deck[deck.size() - 1]);
			deck.pop_back();
		}
		if (turn >= 2)
		{
			player.showHand();
			std::cout << "Player value:" << player.pValue() << std::endl;
			std::cout << "###########################" << std::endl;
			house.showHand();
			std::cout << "House value:" << house.pValue() << std::endl;

		}
		if (player.pValue() > 21)
		{
			choice = 'y';
			break;
		}
		if (house.pValue() > 21)
		{
			choice = 'y';
			break;
		}
		if (turn >= 2)
		{
			std::cout << "More? (y/n)" << std::endl;
			std::cin >> choice;

		}

	}
	while (house.pValue() < 17)
	{
		std::cout << "HHHHHHHHHHHHHHHHHHH" << std::endl;
		if (house.pValue() < 17)
		{
			house.addObj(*deck[deck.size() - 1]);
			deck.pop_back();
		}
		house.showHand();

		std::cout << "House value: " << house.pValue() << std::endl;
		std::cout << "HHHHHHHHHHHHHHHHHHH" << std::endl;
	}
	if (house.pValue() > 21 && player.pValue() <= 21)
	{
		std::cout << "You won!" << std::endl;
	}
	else if (player.pValue() > 21)
	{
		std::cout << "You lost!" << std::endl;
	}

	else if (player.pValue() == house.pValue())
	{
		std::cout << "It's a tie!" << std::endl;
	}

	else if (player.pValue() > house.pValue() && player.pValue() <= 21)
	{
		std::cout << "You won!" << std::endl;
	}
	else
	{
		std::cout << "You lost!" << std::endl;
	}
}
;
