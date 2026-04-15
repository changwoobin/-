#pragma once
#include "Salesman.h"
class SalesReport
{
private:
	Salesman** team;
	double highestSales;
	double averageSales;
	int m_number;
public:
	SalesReport(const int& number);
	~SalesReport();
	void computeStats();
	Salesman& getBestClerk();
	string getTeamInfo();
	void addMember();
};

