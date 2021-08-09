
//include and "using"
using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "SortedList.cpp"
class SortedArrayList: public SortedList
{
	string* buf;
	int capacity;
	int size;
public:
	SortedArrayList(int max_len)
		: buf{new string[max_len]}, capacity{max_len}, size{0}
	{
	}
	
	SortedArrayList(const SortedArrayList& a) = delete;
	
	SortedArrayList& operator = (const SortedArrayList& a) = delete;

	bool isFull()//O(1)
	{
		if(size == capacity)
		{
			return 1;
		}
		return 0;
	}
		

	bool isEmpty()//O(1)
	{
		if(size == 0)
		{
			return 1;
		}
		return 0;
	}

	int binary_search(string key, string buf[], int min, int max)//O(Log N)
	{
		int mid;
		while(min <= max)
		{
			mid = min + (max - min)/2;
			if(key < buf[mid])
			{
	
				max = mid - 1;
			}
			else if(key > buf[mid])
			{

				min = mid + 1;
			}
			else
			{

				return mid;
			}
		}
		if(buf[min] > key)
		{
			return min;
		}
		else
		{
			return min-1;
		}
	}
	
				
	void copy_down(int hole)//O(N)
	{
		for(int i = size; i > hole; --i)
		{
			buf[i] = buf[i-1];
		}
		++size;	
	}

	void copy_up(int hole)//O(N)
	{
		for(int i = hole; i < size; ++i)
		{
			buf[i] = buf[i+1];
		}
		--size;
	}

	void insert(string word)//O(N)
	{
		int loc =  binary_search(word, buf, 0, size);

		copy_down(loc);
		buf[loc] = word;
	}

	bool find(string word)//O(log N)
	{
		
		int result = binary_search(word, buf, 0, size);
		if(buf[result] == word)
		{
			return 1;
		}
		return 0;
	}


	void remove(string word)// O(N)
	{
		int loc = binary_search(word, buf, 0, size);
		if(find(word))
		{
			copy_up(loc);
		}
			
	}

	void print(ostream & out)//O(N)
	{
		for(int i = 0; i < size; ++i)
		{
			out << buf[i] << endl;
		}
	}
	~SortedArrayList()//O(1)
	{
		delete[] buf;
	}
};

