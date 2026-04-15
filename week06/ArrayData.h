#pragma once
#include <memory>
using namespace std;

class ArrayData
{
private:			
	//shared_ptr<double[]> data;
	unique_ptr<double[]> data;
	int capacity;
	int used;	
public:
	ArrayData();	
	ArrayData(const int& capacity);
	ArrayData(ArrayData& arr);
	ArrayData(ArrayData&& arr) noexcept;
	~ArrayData();
	void addElement(const double& num);
	bool full() const;
	void emptyArray();
	void showData() const;	
	int getCapacity() const {
		return this->capacity;
	};
	int getUsed() const {
		return this->used;
	};
};

