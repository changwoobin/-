#include "SalesReport.h"
#include <iostream>
using namespace std;

SalesReport::SalesReport(const int& number) 
	: m_number(number), highestSales(0.0), averageSales(0.0)
{
	if (m_number > 0) {
		team = new Salesman * [m_number];

	}
	else
		team = nullptr;
}

SalesReport::~SalesReport()
{
	cout << "SalesReport 소멸자" << endl;
	if (team != nullptr) {
		for (int i = 0; i < m_number; i++) {
			delete team[i];
		}
		delete[] team;
		team = nullptr;
	}
}

void SalesReport::computeStats()
{
	if (team != nullptr) {
		double sum = team[0]->getSales();
		highestSales = team[0]->getSales();
		for (int i = 0; i < m_number; i++) {
			if (highestSales < team[i]->getSales()) {
				highestSales = team[i]->getSales();
			}
			sum += team[i]->getSales();
		}
		averageSales = sum / m_number;
	}
}

Salesman& SalesReport::getBestClerk()
{
	int bestIndex = 0;
	for (int i = 0; i < m_number; i++) {
		if (team[bestIndex]->getSales() < team[i]->getSales()) {
			bestIndex = i;
		}
	}

	return *team[bestIndex];
}

string SalesReport::getTeamInfo()
{
	if (team != nullptr) {
		string info = "인원 수 : " + to_string(m_number);
		info += "\n최고판매금액 : " + to_string(highestSales);
		info += "\n평균판매금액 : " + to_string(averageSales) + "\n";
		for (int i = 0; i < m_number; i++) {
			info += team[i]->getSalesmanInfo() + "\n";
		}
		return info;
	}
	else {
		return "등록된 정보가 없습니다.";
	}
	
}

void SalesReport::addMember()
{
	if (team != nullptr) {
		string name;
		double sales;
		for (int i = 0; i < m_number; i++) {
			cout << "이름 : ";
			cin >> name;
			cout << "실적 : ";
			cin >> sales;
			team[i] = new Salesman(name, sales);
		}
	}
	
}
