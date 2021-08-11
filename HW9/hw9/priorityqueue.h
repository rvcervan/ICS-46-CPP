#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

template <typename myType>

class PriorityQueue
{

	int capacity, front, rear;
	myType* buf;	

public:
	
	PriorityQueue(int cap)
		:capacity(cap+1), front(0), rear(0),
		 buf(new myType[cap+1]){}
	
	void enqueue(myType item)
	{
        	if(isFull()){error("enqueue on a full queue");}
        	buf[rear] = item;
        	rear = (rear + 1) % capacity;
	}

	myType dequeue()
	{
	        if(isEmpty()){error("dequeue on an empty queue");}
	        myType i = buf[front];
	        front = (front + 1) % capacity;
	        return i;
	}
	
	myType peek()
	{
	        if(isEmpty()){error("peek on empty queue");}
	        return buf[front];
	}
	
	void setFrontZero(int src)
	{
	        buf[src].dist = 0;
		//apsort(buf, capacity);
	}

	bool isEmpty()
	{
	        return front == rear;
	}
	
	bool isFull()
	{
        	return (rear+1) % capacity == front;
	}

	void error(string msg)
	{
	        cout << msg << endl;
        	throw;
	}

	int leftChild(int i)
	{
	        return 2*i + 1;
	}

	int rightChild(int i)
	{
	        return 2*i + 2;
	}

	int Parent(int i)
	{
        	return floor((i-1) / 2);
	}

	void heapsort(myType A[], int count)
	//O(N^2)
	{
	        heapify(A, count);
	
	        int end = count - 1;
	        while(end > 0)
	        {
	                swap(A[end], A[0]);
	                end = end - 1;
        	        siftSmallestUp(A, 0, end);//O(N)
	        }
	}

	void heapify(myType A[], int N)
	{
	        int end = 1;
	        while(end < N)
	        {
	                siftSmallestUp(A, 0, end);
	                end = end + 1;
        	}
	}
	
	void siftSmallestUp(myType A[], int start, int end)
	{
	        int child = end;
        	while(child > start)
	        {
	                int parent = Parent(child);
	                if(A[parent].dist < A[child].dist)
	                {
	                        swap(A[parent], A[child]);
	                        child = parent;
	                }
	                else
	                {
                        	return;
                	}
        	}
	}
	
	void decreaseKey(int id, int dst)
	//O(N^2)
	{
	
		
		for(int i = 0; i < capacity; ++i)
		{
			if(buf[i].id == id)
			{
			//	cout << dst << endl;
				buf[i].dist = dst;
				break;
			}
		}
	
		//cout << id << " " << dst <<  endl;
	        heapsort(buf, capacity);

	}

	~PriorityQueue()
	{
		delete[] buf;
	}
};
/*
template <typename myType>

PriorityQueue<myType>::PriorityQueue(int cap)
        : capacity(cap+1), front(0), rear(0),
          buf(new myType[cap+1]){}

template <typename myType>
void PriorityQueue<myType>::enqueue(myType item)
{
        if(isFull()){error("enqueue on a full queue");}
        buf[rear] = item;
        rear = (rear + 1) % capacity;
}

template <typename myType>
myType PriorityQueue<myType>::dequeue()
{
        if(isEmpty()){error("dequeue on an empty queue");}
        myType i = buf[front];
        front = (front + 1) % capacity;
        return i;
}

template <typename myType>
myType PriorityQueue<myType>::peek()
{
        if(isEmpty()){error("peek on empty queue");}
        return buf[front];
}

template <typename myType>
void PriorityQueue<myType>::setFrontZero()
{
        buf[front].distance = 0;
}

template <typename myType>
bool PriorityQueue<myType>::isEmpty()
{
        return front == rear;
}

template <typename myType>
bool PriorityQueue<myType>::isFull()
{
        return (rear+1) % capacity == front;
}

template <typename myType>
void PriorityQueue<myType>::error(string msg)
{
        cout << msg << endl;
        throw;
}

template <typename myType>
int PriorityQueue<myType>::leftChild(int i)
{
        return 2*i + 1;
}

template <typename myType>
int PriorityQueue<myType>::rightChild(int i)
{
        return 2*i + 2;
}

template <typename myType>
int PriorityQueue<myType>::Parent(int i)
{
        return floor((i-1) / 2);
}

template <typename myType>
void PriorityQueue<myType>::heapsort(myType A[], int count)
{
        heapify(A, count);

        int end = count - 1;
        while(end > 0)
        {
                swap(A[end], A[0]);
                end = end - 1;
                siftSmallestUp(A, 0, end);
        }
}

template <typename myType>
void PriorityQueue<myType>::heapify(myType A[], int N)
{
        int end = 1;
        while(end < N)
        {
                siftSmallestUp(A, 0, end);
                end = end + 1;
        }
}

template <typename myType>
void PriorityQueue<myType>::siftSmallestUp(myType A[], int start, int end)
{
        int child = end;
        while(child > start)
        {
                int parent = Parent(child);
                if(A[parent].distance < A[child].distance)
                {
                        swap(A[parent], A[child]);
                        child = parent;
                }
                else
                {
                        return;
                }
        }

}

template <typename myType>
void PriorityQueue<myType>::decreaseKey(int id, int dst)
{
        bool running = 1;
        int i = 0;
        while(running)
        {

                if(i > capacity)
                {
                        running = 0;
                }
                if(buf[i].id = id)
                {
                        buf[i].distance = dst;
                        running = 0;
                }
        }

        heapsort(buf, capacity);

}

template <typename myType>
PriorityQueue<myType>::~PriorityQueue()
{
        delete[] buf;
}
*/

#endif
