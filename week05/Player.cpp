#include "Player.h"

Player::Player(const string& name)
{
	this->name = name;
}

void Player::setName(const string& name)
{
	this->name = name;
}


string Player::getName()
{
	return name;
}

void Player::roll(Dice& dice1, Dice& dice2)
{
	dice1.roll();
	dice2.roll();
	total = dice1.getFaceValue() + dice2.getFaceValue();
}

int Player::getTotal()
{
	return total;
}
