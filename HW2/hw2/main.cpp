#include <iostream>
#include <string>
#include "Timer.h"
#include <fstream>
#include "UnorderedArrayList.cpp"
#include "UnorderedLinkedList.cpp"

void insert_all_words(string file_name, UnorderedArrayList& L)//O(N)
{
/*
	declare time object
	open file
	start timer
	for each word, w, in file
		L.insert(w);
	stop time
	close file
	report time
*/
	Timer t;
	double eTime;
	ifstream file;
	file.open(file_name);
	t.start();

	string word;
	while(file >> word)
	{	
		L.insert(word);//1002N
//		cout << word << endl;	
	}
	t.elapsedUserTime(eTime);
	cout << eTime << endl;
	file.close();
}

void find_all_words(string file_name, UnorderedArrayList& L)//O(N^2)
{
	Timer t;
	double eTime;
	ifstream file;
	file.open(file_name);	
	t.start();
	
	string word;	
	while(file >> word)
	{
		//cout << word << endl;
		L.find(word);//5N^2 + 2N
	}
	t.elapsedUserTime(eTime);
	cout << eTime << endl;
	file.close();

}

void remove_all_words(string file_name, UnorderedArrayList& L)//O(N^2)
{
	Timer t;
	double eTime;
	ifstream file;
	file.open(file_name);
	t.start();

	string word;
	while(file >> word)
	{
		L.remove(word);//6N^2 + N
	}
	t.elapsedUserTime(eTime);
	cout << eTime << endl;
	file.close();

}

void insert_all_words(string file_name, UnorderedLinkedList& L)//O(N)
{
	Timer t;
	double eTime;
	ifstream file;
	file.open(file_name);
	t.start();
	
	string word;
	while(file >> word)
	{
		L.insert(word);//1002N
	}
	
	t.elapsedUserTime(eTime);
	cout << eTime << endl;
	file.close();
	
}

void find_all_words(string file_name, UnorderedLinkedList& L)//O(N^2)
{
	///*
	Timer t;
	double eTime;
	ifstream file;
	file.open(file_name);
	t.start();
	
	string word;
	while(file >> word)
	{
		//cout << L.find(word) << endl;
		L.find(word);//4N^2 + 5N
	}
	
	t.elapsedUserTime(eTime);
	cout << eTime << endl;
	file.close();
	//*//
}

void remove_all_words(string file_name, UnorderedLinkedList& L)//O(N^2)
{
	Timer t;
	double eTime;
	ifstream file;
	file.open(file_name);
	t.start();
	
	string word;
	while(file >> word)
	{
		L.remove(word);//6N^2 + 1012N
	}
	
	t.elapsedUserTime(eTime);
	cout << eTime << endl;
	file.close();
}

void test_UnorderedArrayList_methods(string file_name, UnorderedArrayList& L)
{
	cout << "Testing UnorderedArrayList:" << endl;
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}

void test_UnorderedLinkedList_methods(string file_name, UnorderedLinkedList& L)
{
	cout << "Testing UnorderedLinkedList:" << endl;
	insert_all_words(file_name, L);
	find_all_words(file_name, L);
	remove_all_words(file_name, L);
}

int main(int argc, char* argv[])
{
	const char* input_file = argc == 2 ? argv[1] : "random.txt";
	UnorderedArrayList UAL(45500);
	test_UnorderedArrayList_methods(input_file, UAL);
	UnorderedLinkedList ULL;
	test_UnorderedLinkedList_methods(input_file, ULL);
	return 0;
}
