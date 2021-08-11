using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "TreeNode.cpp"
#include "Timer.h"
#define NPartitions 10
#define NSamples 45392

void insertAll(ifstream& file,SearchTree<string, int>& S, int NWords)
{
	string word;
	for(int i = 0; i < NWords; ++i)
	{	
		file >> word;
		S.insert(word, i);
	}
//	S.count();
}

void findAll(ifstream& file, SearchTree<string, int>& S, int NWords)
{
	string word;
	for(int i = 0; i < NWords; ++i)
	{
		file >> word;
		S.find(word);
	}
}
	
void removeAll(ifstream& file, SearchTree<string, int>& S, int NWords)
{
	string word;
	for(int i = 0; i < NWords; ++i)
	{
		file >> word;
		S.remove(word);
	}
	//S.countLengths();
}

int measure_TreeNode(string inputFileName, int NWords, int part)
{
	ifstream in(inputFileName);
	SearchTree<string, int> ST;
	Timer t1, t2, t3;
	double t1Time, t2Time, t3Time;
	
	t1.start();
	insertAll(in, ST, NWords);
	t1.elapsedUserTime(t1Time);
	
	in.clear();
	in.seekg(0, ios::beg);

	t2.start();	
	findAll(in, ST, NWords);
	t2.elapsedUserTime(t2Time);
	
	in.clear();
	in.seekg(0, ios::beg);

	
	t3.start();
	removeAll(in, ST, NWords);
	t3.elapsedUserTime(t3Time);
	
	in.close();
	
	cout << "File: " << inputFileName << ". Partition: " << part << "/10. Function: insertAllWords.  Time: "<< t1Time << endl;		
	cout << "File: " << inputFileName << ". Partition: " << part << "/10. Function: findAllWords.    Time: "<< t2Time << endl;		
	cout << "File: " << inputFileName << ". Partition: " << part << "/10. Function: removeAllWords.  Time: "<< t3Time << endl;		
	cout << endl;

	return 1;	
}
	
void printAllWords(string inputFileName)
{
	ifstream in(inputFileName);
	SearchTree<string, int> ST;
	
	insertAll(in, ST, NSamples);
	ST.countLengths();
}

int partitions(string inputFileName)
{
	for(int i = 1; i <= NPartitions; ++i)
	{
		//cout << i*NSamples/NPartitions << endl;
		measure_TreeNode(inputFileName, i*NSamples/NPartitions, i);
	}

	return 0;
}

int main()
{
	//cout << "Testing TreeNode" << endl;
	string file = "random.txt";
	partitions(file);
	printAllWords(file);
	
	return 0;
}
