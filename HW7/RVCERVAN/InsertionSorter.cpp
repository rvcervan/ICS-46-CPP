
using namespace std;
#include <string>
#include <iostream>
#include "InsertionSorter.h"
#include "Sorter.h"

	InsertionSort::InsertionSort(int max_len)
		:Sorter(max_len){}

	void InsertionSort::sort()
	{
		InsertSort(buf, capacity);
	}

	void InsertionSort::InsertSort(string A[], int n)
	//Big-O = O(N^2)
	{
	
		int i = 1;
		while(i < n)
		{
			int j = i;
			while (j>0 && A[j-1] > A[j])
			{
				swap(A[j],  A[j-1]);
				j = j-1;
			}
			i = i + 1;
		}

	}
	
	InsertionSort::~InsertionSort()
	{
		delete[] buf;
	}

