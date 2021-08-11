#ifndef QUICKSORTER_H
#define QUICKSORTER_H
using namespace std;
#include <string>
#include "Sorter.h"

class QuickSort: public Sorter
{
//	string* buf;
//	int capacity;
//	int size;
	static void InsertionSort(string A[], int n)
	{
		int i = 1;
		while(i<n)
		{
			int j = i;
			while(j>0 && A[j-1] > A[j])
			{
				swap(A[j], A[j-1]);
				j = j-1;
			}
			i = i + 1;
		}
	}

public:
	
	QuickSort(int max_len);
	
	QuickSort(const QuickSort& h) = delete;
	
	QuickSort& operator = (const QuickSort& h) = delete;
	
	void printAll();
	
	void sort();
	
	void quick_sort(string A[], int low, int high);
	
	int partition(string A[], int low, int high);
	
	string median_of_three(string A[], int low, int high);
	
	~QuickSort();
};

#endif
