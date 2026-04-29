#pragma once
#include "Ticket.h"

class GeneralTicket : public Ticket
{
protected:
	bool payByCredit;
public:
	GeneralTicket(const double& p, const bool& payByCredit);
	double getPrice() const;
	bool getPayByCredit() const;
	void show() const;
};

