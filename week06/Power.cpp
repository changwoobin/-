#include "Power.h"
#include <iostream>
using namespace std;

void Power::show()
{
	cout << "kick=" << kick << "," << "punch=" << punch << endl;
}

Power Power::operator+(Power op2)
{
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

bool Power::operator==(Power op2)
{
	
	return kick == op2.kick && punch == op2.punch;
}

Power& Power::operator+=(Power op2)
{
	kick += op2.kick;
	punch += op2.punch;
	return *this;
}

Power Power::operator+(int op2)
{
	Power tmp;
	tmp.kick = kick + op2;
	tmp.punch = punch + op2;
	return tmp;
}
