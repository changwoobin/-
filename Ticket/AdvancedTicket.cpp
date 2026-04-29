#include "AdvancedTicket.h"
#include <iostream>
using namespace std;

AdvancedTicket::AdvancedTicket(const double& p, const int& a)
	:Ticket(p)
{
	advanceDays = a;
}
double AdvancedTicket::getPrice() const {
	return price;
}
int AdvancedTicket::getAdvanceDays() const {
	return advanceDays;
}
void AdvancedTicket::show() const {
	cout << "티켓번호 : " << number << endl;
	cout << "가격정보 : " << price << endl;
	cout << "사전예약일 : " << advanceDays << endl;
	
	if (advanceDays >= 30) {
		cout << "지불금액 : " << price * 0.5 << endl;
	}
	else if (advanceDays >= 20) {
		cout << "지불금액 : " << price * 0.7 << endl;
	}
	else if (advanceDays >= 10) {
		cout << "지불금액 : " << price * 0.9 << endl;
	}
	else {
		cout << "지불금액 : " << price << endl;
	}
}