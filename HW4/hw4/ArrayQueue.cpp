using namespace std;
#include <iostream>
#include <string>
#include "Queue.cpp"

template
	<typename object>

class ArrayQueue: public Queue<object>
{

	int capacity, front, rear;
	object* buf;
public:	
	ArrayQueue(int maxSize)
		: capacity(maxSize+1), front(0), rear(0),
		  buf(new object[maxSize+1])
	{}

	ArrayQueue(const ArrayQueue<object>& A) = delete;
	
	ArrayQueue& operator = (const ArrayQueue<object>& A) = delete;

	void enque(object s)// O(1)
	{
		if(isFull()){error("enque on a full queue");}
		buf[rear] = s;
		rear = (rear + 1) % capacity;
	}
	
	object deque()//O(1)
	{
		if(isEmpty()){error("deque on an empty queue");}
		object s = buf[front];
		front = (front + 1) % capacity;
		return s;
	}
	
	object peek()//O(1)
	{
		if(isEmpty()){error("peek on an empty queue");}
		return buf[front];
	}
	
	bool isEmpty()//O(1)
	{
		return front == rear;
	}
	
	bool isFull()//O(1)
	{
		return (rear+1) % capacity == front;
	}
	
	void error(string msg)//O(1)
	{
		cout << msg << endl;
		throw;
	}
		

	~ArrayQueue()//O(1)
	{
		delete[] buf;
	}
};
