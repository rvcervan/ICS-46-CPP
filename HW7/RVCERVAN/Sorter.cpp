
using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "Timer.h"
#include "Sorter.h"
#define NWords 45293
	Sorter::Sorter(int max_len)
		:buf(new string[max_len]), capacity(max_len)
	{
	}
	
	void Sorter::insertAllFromFile(int partition, string fileName, string Sorter)
	//Big-O = O(N)
	{
		ifstream in(fileName);
		Timer t1;
		double t1Time;
		
		string word;
		for(int i = 0; i < capacity; ++ i)
		{
			in >> word;
			buf[i] = word;
		}
	
		t1.start();
		sort();
		t1.elapsedUserTime(t1Time);
		in.close();
		
		cout << "File: "<< fileName<< ". Partition: "<< 
		partition<< "/10. Sorter: "<< Sorter << "  Time: "<< t1Time<< endl;	
	}
	
	void Sorter::print(ostream& out)
	{
		out << buf[0] << endl;
	}

	
