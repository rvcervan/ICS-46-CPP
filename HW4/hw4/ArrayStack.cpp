using namespace std;
#include <iostream>
#include <string>
#include "Stack.cpp"

template
	<typename object>

class ArrayStack: public Stack<object>
{
	int capacity, tp;
	object* buf; // base of array
public:
	ArrayStack(int maxSize)
		: capacity(maxSize), tp(0), buf(new object[maxSize])
	{}

	ArrayStack(const ArrayStack<object>& A) = delete;
	
	ArrayStack& operator = (const ArrayStack<object>& A) = delete;

	void push(object s)//O(1)
	{
		if(isFull()){error("Push on a full stack");}
		buf[tp++] = s;
	}
	
	object pop()//O(1)
	{

		if(isEmpty()){error("Pop on an empty stack");}
		return buf[--tp];
	}
	
	object top()//O(1)
	{

		if(isEmpty()){error("Top on an empty stack");}
		return buf[tp-1];
	}

	bool isEmpty()//O(1)
	{
		return tp<=0;	
	}
		
	bool isFull()//O(1)
	{
		return tp>= capacity;
	}
	
	void error(string msg)//O(1)
	{
		cout << msg << endl;
		throw;
	}

	~ArrayStack()//O(1)
	{
		delete[] buf;
	}

};
