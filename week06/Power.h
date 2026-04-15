#pragma once
class Power
{
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power operator+(Power op2);
	bool operator==(Power op2);
	Power& operator+=(Power op2);
	Power& operator+(int op2);
};

