#pragma once
class Dice
{
private:
	int faceValue;
public:
	Dice() : faceValue(0) {}
	void roll();
	int getFaceValue();
};

