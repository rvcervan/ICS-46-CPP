using namespace std;
#include <string>
#include <math.h>
#include <iostream>
#include "HeapSorter.h"
#include "Sorter.h"
	
	HeapSort::HeapSort(int max_len)
		:Sorter(max_len){}
	
	
	void HeapSort::printAll()
	//Big-Oh = O(N)
	{
		for(int i = 0; i < capacity; ++i)
		{
			cout << buf[i] << endl;
		}
	}

	void HeapSort::sort()
	//Big-Oh = O(N)
	{
		heapSort(buf, capacity);
	//	printAll();
	}

	int HeapSort::leftChild(int i)
	//Big-Oh = O(1)
	{
		return 2*i + 1;
	}

	int HeapSort::rightChild(int i)
	//Big-Oh = O(1)
	{
		return 2*i + 2;
	}
	
	int HeapSort::Parent(int i)
	//Big-Oh = O(1)
	{
		return floor((i-1) / 2);
	}

	void HeapSort::heapSort(string A[], int N)
	//Big-Oh = O(N^2)
	{
		heapify(A, N);
		
		int end = N-1;
		while(end > 0)
		{
			swap(A[end], A[0]);
			end = end - 1;
			siftSmallestDown(A, 0, end);
		}
	}
	
	void HeapSort::heapify(string A[], int count)
	//Big-Oh = O(N^2)
	{
		int start = Parent(count-1);
		
		while(start >= 0)
		{
			siftSmallestDown(A, start, count - 1);
			start = start - 1;
		}
	}
	

	void HeapSort::siftSmallestDown(string A[], int start, int end)
	//Big-Oh = O(N)
	{
		int root = start;
		while(leftChild(root) <= end)
		{
			int child = leftChild(root);
			int to_swap = root;
			if(A[to_swap] < A[child])
			{
				to_swap = child;
			}
			if(child + 1 <= end && A[to_swap] < A[child + 1])
			{
				to_swap = child + 1;
			}
			if(to_swap == root)
			{
				return;
			}
			else
			{
				swap(A[root], A[to_swap]);
				root = to_swap;
			}
		}
	}

	HeapSort::~HeapSort()
	{
		delete[] buf;
	}
