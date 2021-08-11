#include "Timer.h"
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>
//#include "hashfunction.cpp"
using namespace std;


//an abstract struct to parent your various hasher classes
struct Hasher
{
	virtual int hash(string s, int N) = 0;
};

struct GeneralStringHasher: Hasher
{
	int hash(string key, int N)//O(N)
	{
		//use the "General Hash Function for Strings"
		//algrorithim from lecture
		const unsigned shift = 6;
		const unsigned zero = 0;
		int size = key.size();
		unsigned mask = ~zero >> (32-shift); // low 6 bits on
		unsigned result = 0;
		int len = min(size, 6);
		for (int i = 0; i < len; i++)
		{
			result = (result << shift) | (key[i] & mask);
		}
		return result % N;
	}
};

struct SumHasher: Hasher
{
	int hash(string key, int N)//O(N)
	{
		int result = 0;
		for(unsigned int i = 0; i<key.size(); ++i)
			result += key[i];
		return abs(result)%N;
	}
};

struct ProdHasher: Hasher
{
	int hash(string key, int N)//O(N)
	{
		int result = 1;
		for(unsigned int i = 0; i<key.size(); ++i)
			result *= key[i];
		return abs(result)%N;
	}
};

class ChainedHashTable
{
private:
	//data members
	//hint: have a data member that is a Hasher REFERENCE
	//(make sure you understand why!!!)

	struct ListNode
	{
		string key;
		int value;
		ListNode* next;
		ListNode(string new_key, int new_value, ListNode* new_next)
			: key(new_key), value(new_value), next(new_next) {}
		
		ListNode(const ListNode& ln) = delete;
		
		ListNode& operator = (const ListNode& ln) = delete;
		
		static ListNode* insert(string key, int val, ListNode* L)//O(1)
		{
			return new ListNode(key, val, L);
		}	

		static ListNode* find(string key, ListNode* L)//O(N)
		{
			for(ListNode* p = L; p!=nullptr; p = p->next)
			{
				if(p->key == key)
				{
					return p;
				}
			}
			return nullptr;
		}
	
		static ListNode* remove(string key, ListNode* L)//O(N)
		{		
			ListNode* p = L;
			if(p == nullptr)
			{
				return nullptr;
			}
			if(p->next == nullptr)
			{
				if(p->key == key)
				{
					delete p;
					return nullptr;
				}
				return L;
			}
			ListNode* prev = p;
			while(p != nullptr)
			{
				p = p->next;
				if(p == nullptr)
				{
					return L;
				}
				if(p->key == key)
				{
					prev->next = p->next;
					delete p;
					return L;
				}
				prev = prev->next;
			}
			return L;
		}
		
		static ListNode* copy(ListNode* L)//O(N)
		{
			ListNode* result = nullptr;
			for(ListNode* p = L; p!=nullptr; p = p->next)
			{
				result = new ListNode(p->key, p->value, result);
			}
			return result;	
		}
	};

	ListNode** buf;
	int capacity;
	Hasher& myHash;
	int size;
	int* stat;
public:
	ChainedHashTable(int cap, Hasher& myHasher)//O(N)
		: buf(new ListNode*[cap]), capacity(cap), myHash(myHasher), size(0), stat(new int [cap])
	{
		for(int i = 0; i < capacity; ++i)
		{
			buf[i] = nullptr;
			stat[i] = 0;
		}
	}


	ChainedHashTable(const ChainedHashTable& C)//O(N^2)
		:  capacity(C.capacity), myHash(C.myHash), size(C.size), stat(C.stat)
	{
		buf = new ListNode*[capacity];
		stat= new int[capacity];
		
		for(int i = 0; i < capacity; ++i)
		{
			stat[i] = C.stat[i];
			buf[i] = ListNode::copy(C.buf[i]);
		}
	}

	void insert(string key, int val)//O(N)
	{
		int index = myHash.hash(key, capacity);
		ListNode* temp = ListNode::insert(key, val, buf[index]);
		++stat[index];
		++size;
		buf[index] = temp;
	}

	bool find(string key)//O(N)
	{
		int index = myHash.hash(key, capacity);
		ListNode* temp = ListNode::find(key, buf[index]);
		if(temp == nullptr)
		{
			return 0;
		}
		return 1;
	}

	void remove(string key)//O(N)
	{
		int index = myHash.hash(key, capacity);
		ListNode* temp = ListNode::remove(key, buf[index]);
		buf[index] = temp;
	}

	int& operator[] (string key)//O(N)
	{
		int index = myHash.hash(key, capacity);
		ListNode* temp = ListNode::find(key, buf[index]);
		if(temp == nullptr)
		{
			throw;
		}
		return temp->value;
	}
	
	int max()//O(N)
	{
		int result = 0;
		for(int i = 0; i < capacity; ++i)
		{
			if(stat[i] > result)
			{
				result = stat[i];
			}
		}
		return result;
	}

	int min()//O(N)
	{
		int smol = stat[0];
		for(int i = 0; i < capacity; ++i)
		{
			if(stat[i] < smol)
			{
				smol = stat[i];
			}
		}
		return smol;
	}
	
	double avg()//O(1)
	{
		return size*1.0/capacity*1.0;	
	}

	double SD()//O(N)
	{	
		double variance_sum = 0.0, variance = 0.0, std_dev = 0.0;
		for(int i = 0; i < capacity; ++i)
		{
			variance_sum += (stat[i] - avg())*(stat[i] - avg());
		}
		variance = variance_sum / capacity;
		std_dev = sqrt(variance);
		return std_dev;
	}
	
		
	ChainedHashTable& operator = (const ChainedHashTable& C) = delete;

	~ChainedHashTable()//O(N^2)
	{
		for(int i = 0; i < capacity; ++i)
		{
			ListNode* knob = buf[i];
			while(knob != nullptr)
			{
				ListNode* temp = knob;
				knob = knob->next;
				delete temp;
			}
		}
		delete[] buf;	
		delete[] stat;
	}
	
};


//individual method-testing functions//

void testConstructor(Hasher& hasher)//O(N^2)
{
	ChainedHashTable A(5000, hasher);
	//create an empty ChainedHashTable object
}

void testCopyConstructor(Hasher& hasher)//O(N^2)
{
	ChainedHashTable A(5000, hasher);
	ChainedHashTable B(A);
	//create a ChainedHashTable object
	//create a second object as a copy of the first object
}

void insertAll(ifstream& file, ChainedHashTable& C, int NWords)//O(N^2)
{
	string word;
	for(int i = 0; i < NWords; file >> word, ++i)
	{
		C.insert(word, 1);
	}
}

void findAll(ifstream& file, ChainedHashTable& C, int NWords) //O(N^2)
{
	string word;
	for(int i = 0; i < NWords; file >> word, ++i)
	{
		C.find(word);
	}
}

void removeAll(ifstream& file, ChainedHashTable& C, int NWords)//O(N^2)
{

	string word;
	for(int i = 0; i < NWords; file >> word, ++i)
	{
		C.remove(word);
	}
}

#define NPartitions 10
#define NSamples 45392
void measure(string file_name, int NWords, Hasher& hasher)
{
	ifstream in(file_name);
	ChainedHashTable myTable(5000, hasher);
	Timer t1, t2, t3;
	double t1Time, t2Time, t3Time;	

	t1.start();
	insertAll(in, myTable, NWords);
	t1.elapsedUserTime(t1Time);

	in.clear();
	in.seekg(0, ios::beg);

	t2.start();
	findAll(in, myTable, NWords);
	t2.elapsedUserTime(t2Time);

	in.clear();
	in.seekg(0, ios::beg);
	t3.start();
	removeAll(in, myTable, NWords);
	t3.elapsedUserTime(t3Time);

	in.close();
	cout << "Using " << NWords << " words" << endl;
	cout << "min = " << myTable.min() << "; ";
	cout << "max = " << myTable.max() << "; ";
	cout << "average = " << myTable.avg() << "; ";
	cout << "std_dev = " << myTable.SD() << "; " << endl;
	//cout << "Using " << NWords << " words" << endl;
	cout << "insertAll: " << t1Time << endl;
	cout << "findAll: " << t2Time << endl;
	cout << "removeAll: " << t3Time << endl;
	cout << endl;
}
//overall tester function

void testHasher(char const* inputFileName, Hasher& hasher)
{

	//cout << inputFileName << hasher.hash("hello", 5000) << endl;
	testConstructor(hasher);
	testCopyConstructor(hasher);
	

	for(int i = 1; i <= NPartitions; ++i)
	{
		cout << "k = " << i << endl;
		measure(inputFileName, i*NSamples/NPartitions, hasher); 
	}
	//hainedHashTable A(5000, hasher);
	
	//insertAll(inputFileName, A);
	//findAll(inputFileName, A);
	//removeAll(inputFileName, A);
	//call test functions
	
	//you may want to instantiate a ChainedHashTable
	//object to pass as a  reference to some of your
	//more advanced testing functions
}

int main()
{
	GeneralStringHasher h;
	SumHasher i;
	ProdHasher j;
	cout << "With text file random.txt" << endl;
	cout << "---------Using GeneralStringHasher-----------" << endl;
	testHasher("random.txt", h);
	
	cout << "---------Using SumHasher-----------" << endl;
	testHasher("random.txt", i);

	cout << "---------Using ProdHasher------------" << endl;
	testHasher("random.txt", j);

	cout <<"With text file words.txt" << endl;
	cout << "---------Using GeneralStringHasher-----------" << endl;
	testHasher("words.txt", h);
	
	cout << "---------Using SumHasher-----------" << endl;
	testHasher("words.txt", i);

	cout << "---------Using ProdHasher------------" << endl;
	testHasher("words.txt", j);
	return 0;

}

