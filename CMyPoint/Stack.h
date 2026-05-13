#pragma once
//const int MAX = 10;
template <typename T, int MAX = 10>
class Stack
{
private:
	T items[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const T& item);
	bool pop(T& item);
};

template<typename T, int MAX>
Stack<T, MAX>::Stack(): top(0) {}

template<typename T, int MAX>
bool Stack<T, MAX>::isempty() const
{
	return top == 0;
}

template<typename T, int MAX>
bool Stack<T, MAX>::isfull() const
{
	return top == MAX;
}

template <typename T, int MAX>
bool Stack<T, MAX>::push(const T& item)
{
	if (top < MAX) {
		items[top++] = item;
		return true;
	}
	else
		return false;
}
template <typename T>
bool Stack<T> ::pop(T& item)
{
	if (top > 0) {
		item = items[--top];
		return true;
	}
	else
		return false;
}

