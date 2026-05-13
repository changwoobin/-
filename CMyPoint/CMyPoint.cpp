#include "CMyPoint.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, const CMyPoint& p)
{
    out << "( " << p.getX() << " , " << p.getY() << " )";
    return out;
}

int CMyPoint::getX() const
{
    return x;
}

int CMyPoint::getY() const
{
    return y;
}

bool CMyPoint::operator<(const CMyPoint& p)
{
    return x < p.getX();
}

bool CMyPoint::operator>(const CMyPoint& p)
{
    return x > p.getX();
}

CMyPoint CMyPoint::operator=(const CMyPoint& p)
{
    this->x = p.getX();
    this->y = p.getY();
    return *this;
}
