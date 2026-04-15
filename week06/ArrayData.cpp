#include "ArrayData.h"
#include <iostream>
using namespace std;
ArrayData::ArrayData():ArrayData(3)
{
}

ArrayData::ArrayData(const int& capacity):capacity(capacity), used(0)
{
	//data = make_shared<double[]>(capacity);
	data = make_unique<double[]>(this->capacity);
}

ArrayData::ArrayData(ArrayData& arr)
	: ArrayData(arr.capacity)
{
	cout << "복사 생성자" << endl;
	used = arr.used;
	for (int i = 0; i < used; i++) {
		this->data[i] = arr.data[i];
	}
}

ArrayData::ArrayData(ArrayData&& arr) noexcept
	:capacity(arr.capacity), used(arr.used), data(move(arr.data))
{
	cout << "이동 생성자" << endl;
}



ArrayData::~ArrayData() 
{
	/*if (data != nullptr)
		delete[] data;
	data = nullptr;*/
}

void ArrayData::addElement(const double& num) 
{
	if (!full())
		data[used++] = num;
	else
		cout << "빈방이 없음\n";
}

bool ArrayData::full() const 
{
	return this->capacity == this->used;
}

void ArrayData::emptyArray() 
{
	this->used = 0;
}

void ArrayData::showData() const
{
	for (size_t i = 0; i < used; i++)
		cout << data[i] << " ";
	cout << endl;
}

