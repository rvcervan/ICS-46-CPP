#ifndef HEAPSORTER_H
#define HEAPSORTER_H
using namespace std;
#include <string>
#include "Sorter.h"

class HeapSort: public Sorter
{
	//string* buf;
	//int capacity;
	//int size;
public:
	
	HeapSort(int max_len);
	
	HeapSort(const HeapSort& h) = delete;
	
	HeapSort& operator = (const HeapSort& h) = delete;
	
	void printAll();
	
	void sort();
		
	int leftChild(int i);
	
	int rightChild(int i);
	
	int Parent(int i);
	
	void heapSort(string A[], int N);
	
	void heapify(string A[], int count);

	void siftSmallestDown(string A[], int start, int end);
	
	~HeapSort();
};

#endif
