#include <iostream>
#include <string>
#include "CMyPoint.h"
using namespace std;

template <typename T>
void printArr(T* arr, size_t N) {
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template <>
void printArr(char* arr, size_t N) {
	cout << arr << endl;
}

template <typename T, size_t N>
void showArr(T (&arr)[N]) {
	for (auto i : arr) 
	{
		cout << i << "\t";
	}
	cout << endl;
}

int main() {
	int intArr[]{ 1,2,3,4,5 };
	double doubleArr[]{ 2.2,3.5,4.5 };
	string strArr[]{ "greenjoa01","greenjoa02", "greenjoa03" };
	char charArr[]{ 'a','b','c',0 };
	CMyPoint pointArr[]{ CMyPoint(5,3),CMyPoint(8,9), CMyPoint(4,6) };

	showArr(pointArr);
	/*showArr(intArr);
	showArr(doubleArr);*/

	//printArr(intArr, size(intArr));
	//printArr(doubleArr, size(doubleArr));
	//printArr(strArr, size(strArr));
	//printArr(charArr, size(charArr));

	return 0;
}