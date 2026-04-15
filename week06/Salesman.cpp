#include "Salesman.h"
#include <iostream>
using namespace std;

Salesman::Salesman():Salesman("noname", 0.0)
{
}

Salesman::Salesman(const string& name, const double& sales):m_name(name), m_sales(sales)
{
	cout << m_name << "按眉 积己凳" << endl;
}

Salesman::~Salesman()
{
	cout << m_name << "按眉 家戈凳" << endl;
}

void Salesman::setName(const string& name)
{
	m_name = name;
}

void Salesman::readInput()
{
	cout << "捞抚 : ";
	cin >> m_name;
	cout << "角利 : ";
	cin >> m_sales;
}

string Salesman::getSalesmanInfo()
{
	return "捞抚 : " + m_name + ", 角利 : " + to_string(m_sales);
}

double Salesman::getSales()
{
	return m_sales;
}
