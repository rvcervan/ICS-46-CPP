using namespace std;
#include <string>
#include <iostream>
class UnorderedLinkedList
{
	struct ListNode
	{
		string info;
		ListNode* next;
		ListNode(string new_info, ListNode* new_next) :
			info(new_info), next(new_next) { }

		ListNode(const ListNode& ln) = delete;

		ListNode& operator = (const ListNode& ln) = delete;


		static void print(ostream& out, ListNode* L)//T(N) = 1000; O(1)
		{
			if(L)
			{
				out << L->info << endl;//1000 
			}
		}
		
		static ListNode* insert(string s, ListNode* L)//T(N) = 1001; O(1)
		{
			return new ListNode(s, L);//1 + 1000
		}

		static ListNode* find(string s, ListNode* L)//T(N) = 4N + 2; O(N)
		{
			for(ListNode* p = L; p!=nullptr; p = p->next)//1 + N + N
			{
				//ListNode::print(cout, p);
				if(p->info == s)//N
				{
					return p;//N
				}
			}
			return nullptr;//1
		}
		static ListNode* remove(string s, ListNode* L)//T(N) = 6N + 10; O(N)
		{
			ListNode* p = L;//1
			if(p == nullptr)//1
			{
				return nullptr;///throw error  1
			}
			if(p->next == nullptr)//1
			{
				if(p->info == s)//1
				{
					p = p->next;//1
					return nullptr;//1
					
				}
				return nullptr;//1
			}
			ListNode* prev = p;//1
			while(p != nullptr)//N
			{
				p = p->next;//N
				if(p->info == s)//N
				{
					prev->next = p->next;//N
					return p;//N
				}
				prev = prev->next;//N
			}
			return nullptr;//1


		}
	};
	ListNode* head;

public:
	UnorderedLinkedList()
		: head{nullptr}
	{
		
	}
	
	UnorderedLinkedList(const UnorderedLinkedList& l) = delete;

	UnorderedLinkedList& operator = (const UnorderedLinkedList& l) = delete;

	bool isFull()//T(N) = 1; O(1)
	{
		return 0;//1
	}
	
	bool isEmpty()//T(N) = 3; O(1)
	{
		if(head == nullptr)//1
		{
			return 1;//1
		}
		return 0;//1
	}

	void insert(string word)//T(N) = 1002; O(1)
	{
		head = ListNode::insert(word, head);//1 + 1001
	}
	
	bool find(string word)//T(N) = 4N + 5; O(N)
	{
		
		ListNode* temp;
		temp = ListNode::find(word, head);//1 + 4N + 2
		if(temp)
		{
			return 1;//1
		}
		return 0;//1
		
	}
	
	void remove(string word)//T(N) = 6N + 1012; O(N)
	{
		ListNode* temp;
		temp = ListNode::remove(word, head);//1
		
		if(temp != nullptr)//1
		{
			delete temp;//1000
		}
		
	}

	void print(ostream& out)//T(N) = 3N + 1001; O(N)
	{
		for(ListNode* p = head; p != nullptr; p = p->next)//1 + N + N
		{
			out << p->info << endl;//1000 + N
		}
	}
	
	~UnorderedLinkedList()//T(N) = 1003N; O(N)
	{
		
		while(head != nullptr)//N
		{
			ListNode* next = head->next;//N
			delete head;//1000N
			head = next;//N
		}
	}
};
