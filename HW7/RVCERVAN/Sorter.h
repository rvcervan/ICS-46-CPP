#ifndef SORTER_H
#define SORTER_H
#include <string>
#include <iostream>
using namespace std;



class Sorter
{
protected:
	string* buf;
	int capacity;
public:
	Sorter(int max_len);
		
	void insertAllFromFile(int partition, string fileName, string Sorter);
	
	void print(ostream& out);
	
	virtual void sort() = 0;
	
//	~Sorter();
};
	
#endif
