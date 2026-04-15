#include "Dice.h"
#include <cstdlib>

void Dice::roll()
{
	
	faceValue = rand() % 6;
	
}

int Dice::getFaceValue()
{
	return faceValue;
}
