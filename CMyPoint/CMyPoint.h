#pragma once
#include <iostream>
using namespace std;

class CMyPoint
{
private:
	int x, y;
public:
	CMyPoint() = default;
	~CMyPoint() = default;
	CMyPoint(const int& x, const int& y) : x(x), y(y) {}
	int getX() const;
	int getY() const;
};

ostream& operator<<(ostream& out, const CMyPoint& p);