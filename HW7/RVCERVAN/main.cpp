using namespace std;
#include <string>
#include "QuickSorter.h"
#include "HeapSorter.h"
#include "InsertionSorter.h"
#include "Sorter.h"
#include <iostream>
#define NWords 45293
void measureAll(string fileName)
//Big-O = O(N^2)
{
	
	for(int i = 1; i<=10; ++i)
	{
		int word_count = i*NWords/10;
		QuickSort T1(word_count);
		HeapSort T2(word_count);
		InsertionSort T3(word_count);
		
		T1.insertAllFromFile(i,fileName,"QuickSort");
		T2.insertAllFromFile(i,fileName,"HeapSort");
		T3.insertAllFromFile(i,fileName,"InsertionSort");
		cout << endl;
		
	}
}

int main()
{
	string file = "words.txt";
	measureAll(file);
	return 0;
}
