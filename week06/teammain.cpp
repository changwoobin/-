#include <iostream>
#include "Salesman.h"
#include "SalesReport.h"
#include "ArrayData.h"
#include <vector>
using namespace std;

ArrayData getArray(const int& number) {
	ArrayData arr(number);
	return arr;
}

void showArray(ArrayData& arr) {
	cout << __FUNCTION__ << "(&)" << endl;
	arr.showData();
}

void showArray(ArrayData&& arr) {
	cout << __FUNCTION__ << "(&&)" << endl;
	arr.showData();
}

int main() {

	ArrayData arr = getArray(5); // arr(5)
	arr.addElement(5.5);
	arr.addElement(2.5);
	
	showArray(arr);
	showArray(getArray(5));

	/*vector<ArrayData> vec;
	for (int i = 0; i < 5; i++) {
		vec.push_back(ArrayData(5));
	}*/
	/*ArrayData arr1(5);
	arr1.addElement(1);
	arr1.addElement(2);
	arr1.addElement(3);
	ArrayData arr2(arr1);
	arr2.addElement(4);

	arr1.showData();
	arr2.showData();*/

	/*SalesReport team1(4);
	team1.addMember();
	team1.computeStats();
	cout << team1.getBestClerk().getSalesmanInfo() << endl;
	cout << team1.getTeamInfo() << endl;*/

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