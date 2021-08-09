#ifndef SORTEDLIST_CPP
#define SORTEDLIST_CPP
//include and "using"
using namespace std;
#include <string>
#include <iostream>
#include <fstream>
//#include "SortedLinkedList.cpp"
//#include "SortedArrayList.cpp"

class SortedList
{
	public:
		SortedList(){};
		
		//SortedList(int capacity){}		

		virtual void insert(string word) = 0;
		
		virtual bool find(string word) = 0;
		
		virtual void remove(string word) = 0;

		virtual void print(ostream& out) = 0;

		virtual ~SortedList(){};	
};
		
#endif
