//include and "using"
using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "Timer.h"
#include "SortedLinkedList.cpp"
#include "SortedArrayList.cpp"

ostream & operator << (ostream & out, SortedList & L)
{
	L.print(out); return out;
}

void insert_all_words(string file_name, SortedList & L)//SortedArrayList O(N^2)
						       //SortedLinkedList O(N^2)
{

	Timer t;
	double eTime;
	ifstream file;
	file.open(file_name);
	t.start();

	string word;
	while(file >> word)
	{
		L.insert(word);
	}
	t.elapsedUserTime(eTime);
	cout << eTime << endl;
	file.close();
	
}

void find_all_words(string file_name, SortedList & L)//SortedArrayList O(N log N)
						     //SortedLinkedList O(N^2)
{


	//cout << "Testing Find All Words" << endl;
	Timer t;
	double eTime;
	ifstream file;
	file.open(file_name);
	string word;
	t.start();

	while(file >> word)
	{
		L.find(word);
		//cout << L.find(word) << endl;
	}
	t.elapsedUserTime(eTime);
	cout << eTime << endl;
	file.close();
}


void remove_all_words(string file_name, SortedList & L)//SortedArrayList O(N^2)
						       //SortedLinkedList O(N^2)
{

	//cout << "Testing Remove All Words" << endl;
	Timer t;
	double eTime;
	ifstream file;
	file.open(file_name);
	string word;
	t.start();

	while(file >> word)
	{
		L.remove(word);
	}
	t.elapsedUserTime(eTime);
	cout << eTime << endl;
	file.close();
}

void test_SortedList_methods(string file_name, SortedList & L)
{
	//cout << "Testing SortedList:" << endl;
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}

int main(int argc, char * argv[])
{
	const char * input_file = argc == 2 ? argv[1] : "random.txt";
	SortedArrayList UAL(45500);
	cout << "Testing SortedArrayList:" << endl;
	test_SortedList_methods(input_file, UAL);
	SortedLinkedList ULL;
	cout << "Testing SortedLinkedList:" << endl;
	test_SortedList_methods(input_file, ULL);
	return 0;
}
