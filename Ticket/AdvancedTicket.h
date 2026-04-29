#pragma once
#include "Ticket.h"
class AdvancedTicket : public Ticket
{
protected:
	int advanceDays;
public:
	AdvancedTicket(const double& p, const int& a);
	double getPrice() const;
	int getAdvanceDays() const;
	void show() const;
};

