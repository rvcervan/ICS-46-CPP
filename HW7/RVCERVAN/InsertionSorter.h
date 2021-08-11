#ifndef INSERTIONSORTER_H
#define INSERTIONSORTER_H
using namespace std;
#include <string>
#include "Sorter.h"
	
class InsertionSort: public Sorter
{
	//string* buf;
	//int capacity;
	//int size;
public:
	InsertionSort(int max_len);
	
	InsertionSort(const InsertionSort& h) = delete;
	
	InsertionSort& operator = (const InsertionSort& h) = delete;
	
	void sort();
	
	void InsertSort(string A[], int n);
	
	~InsertionSort();
};
	
#endif
