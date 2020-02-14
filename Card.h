#pragma once
#include <string>
#include <vector>
#include "Suit.h"
#include <iostream>

class Card
{
public:
	Card(std::string name, int value, Suit suite);

	~Card();


	void displayCard();
	int getValue();
	std::string getName();
	void changeCardValue(int value);

private:
	std::string _name;
	int _value;
	Suit _suite;
};

