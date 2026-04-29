#include "GeneralTicket.h"
#include <iostream>
using namespace std;

GeneralTicket::GeneralTicket(const double& p, const bool& payByCredit)
	: Ticket(p)
{
	this->payByCredit = payByCredit;
}

double GeneralTicket::getPrice() const {
	return price;
	
}
bool GeneralTicket::getPayByCredit() const {
	return payByCredit;
}
void GeneralTicket::show() const {
	cout << "티켓번호 : " << number << endl;
	cout << "가격정보 : " << price << endl;
	
	if (payByCredit) {
		cout << "카드결재여부 : true"<< endl;
		cout << "지불금액 : " << price * 1.1 << endl;
	}
	else {
		cout << "카드결재여부 : false" << endl;
		cout << "지불금액 : " << price << endl;
	}
}
