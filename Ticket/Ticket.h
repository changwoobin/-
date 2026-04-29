#pragma once

class Ticket
{
protected:
	static int count;
	int number;
	double price;
public:
	Ticket(const double& p);
	int getNumber() const;
	double getPrice() const;
	void setPrice(const double& price);
	void show() const;
};

