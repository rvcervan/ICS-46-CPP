
using namespace std;
#include <string>
#include <iostream>
#include "QuickSorter.h"
#include "Sorter.h"
#define K 16
	QuickSort::QuickSort(int max_len)
		:Sorter(max_len){}

	void QuickSort::printAll()
	//Big-O = O(N)
	{
		for(int i = 0; i < capacity; ++i)
		{
			cout << buf[i] << endl;
		}
	}

	void QuickSort::sort()
	//Big-O = O(N)
	{
		quick_sort(buf, 0, capacity-1);
		//printAll();
	}

	void QuickSort::quick_sort(string A[], int low, int high)
	//Big-O = O(N)
	{
		int slice = high - low;
		if(slice < K)
		{
			QuickSort::InsertionSort(A, slice);//O(N)
		}
		
		else
		{
			int i = partition(A, low, high);
			quick_sort(A, low, i-1);
			quick_sort(A, i+1, high);
		}
	}

	int QuickSort::partition(string A[], int low, int high)
	//Big-O = O(N^2)
	{
		string pivot = median_of_three(A, low, high);
		int below = low, above = high;
		for(;;)
		{
			while(A[below] < pivot) { ++below;}
			while(pivot < A[above]) { --above;}
			if(below < above)
			{
				swap(A[below++], A[above--]);
			}
			else
			{
				break;
			}
		}
		swap(A[below], A[high]);
		return below;
	}

	string QuickSort::median_of_three(string A[], int low, int high)
	//Big-O = O(1)
	{
		int mid = low + (high - low) / 2;
		if(A[mid] < A[low]) swap(A[low], A[mid]);
		if(A[high] < A[low]) swap(A[low], A[high]);
		if(A[mid] < A[high]) swap(A[mid], A[high]);
		return A[high];
	}
	
	QuickSort::~QuickSort()
	{
		delete[] buf;
	}

