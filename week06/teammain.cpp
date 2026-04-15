#include <iostream>
#include "Salesman.h"
#include "SalesReport.h"
using namespace std;

int main() {

	SalesReport team1(4);
	team1.addMember();
	team1.computeStats();
	cout << team1.getBestClerk().getSalesmanInfo() << endl;
	cout << team1.getTeamInfo() << endl;

	/*{
		Salesman s1;
		Salesman s2("±è±æµ¿", 500.0);

		cout << s1.getSalesmanInfo() << endl;
		cout << s2.getSalesmanInfo() << endl;
	}
	Salesman s3("È«±æµ¿", 1000.0);
	Salesman* s4 = new Salesman("°í±æµ¿", 100.0);
	delete s4;*/

	return 0;
}