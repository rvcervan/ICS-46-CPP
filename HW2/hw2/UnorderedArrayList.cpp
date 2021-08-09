#include <string>
#include <iostream>
//#include <fstream>
//#include "Timer.h"

using namespace std;

class UnorderedArrayList
{
	string* buf;
	int capacity;
	int size;
public:
	UnorderedArrayList(int max_len)
		: buf(new string[max_len]), capacity{max_len}, size{0}
	{
	}

	UnorderedArrayList(const UnorderedArrayList& a) = delete;

	UnorderedArrayList& operator = (const UnorderedArrayList& a) = delete;

	bool isFull() //T(N) = 3; O(1)
	{
		if(size == capacity)//1
		{
			return 1;//1
		}
		return 0;//1
	}
	
	bool isEmpty()//T(N) = 3; O(1)
	{
		if(size == 0)//1
		{
			return 1;//1
		}
		return 0;//1
	}
		

	void insert(string word)//T(N) = 1002; O(1)
	{
		buf[size] = word;//1 + 1000(because of new?)
		++size;//1
	}

	bool find(string word)//T(N) = 5N + 2; O(N)
	{	
		for(int i = 0; i < size; ++i)//1 + N + N
		{
			if(buf[i] == word)//N + N
			{
				return 1;//N
			}
		}
		return 0;//1	
	}

	void remove(string word)//T(N) = 6N + 1; O(N)
	{
		for(int i = 0; i < size; ++i)//1 + N + N
		{
			if(buf[i] == word)//N + N
			{
				buf[i] = "";//N
				--size;//N
			}
		}
	}

	void print(ostream& out)//T(N) = 3N + 1; O(N)
	{
		for(int i = 0; i < size; ++i)//1 + N + N
		{
			out << buf[i] << endl;//N
		}
	}

	~UnorderedArrayList()//T(N) = 1000; O(1)
	{
		delete[] buf;//1000
	}
};
