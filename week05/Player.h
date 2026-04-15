#pragma once
#include "Dice.h"
#include <string>
using std::string;

class Player
{
private:
	string name;
	int total;

public:
	Player() = delete;
	Player(const string& name);
	void setName(const string& name);
	string getName();
	void roll(Dice& dice1, Dice& dice2);
	int getTotal();
};

