//include and "using"
using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include "SortedList.cpp"

class SortedLinkedList: public SortedList 
{
	struct ListNode {
		string info;
		ListNode * next;
		ListNode(string new_info, ListNode *new_next) 
			: info(new_info), next(new_next) { }

		ListNode(const ListNode& ln) = delete;

		ListNode& operator = (const ListNode& ln) = delete;
		
		static void print(ostream & out, ListNode *L)//O(N)
		{
			if (L)
			{
				out << L->info << endl;
				print(out, L->next);
			}
		}
		
		static ListNode* remove(string s, ListNode* L)// O(N)
		{
			ListNode* p = L;
			if(p == nullptr)
			{
				return nullptr;
			}
			if(p->next == nullptr)
			{
				if(p->info == s)
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
				if(p->info == s)
				{
					prev->next = p->next;
					delete p;
					return L;
				}
				prev = prev->next;
			}
			return L;
		} 

		static ListNode*  find(string s, ListNode* L)// O(N)
		{
			for(ListNode* p = L; p!=nullptr; p = p->next)
			{
				if(p->info == s)
				{
					return p;
				}
				if(s < p->info)
				{
					return nullptr;
				}
			}
			return nullptr;
		}
		
	};
	ListNode * head;
public:
	SortedLinkedList()
		: head{nullptr}
	{
	}

	SortedLinkedList(const SortedLinkedList& l) = delete;
	
	SortedLinkedList& operator = (const SortedLinkedList& l) = delete;

	bool isFull()//O(1)
	{
		return 0;
	}
		
	bool isEmpty()//O(1)
	{
		if(head == nullptr)
		{
			return 1;
		}
		return 0;
	}

	void insert(string word)// O(N)
	{
		ListNode* p = head;
		if(p == nullptr)
		{
			ListNode* temp = new ListNode(word, head);
			head = temp;
		}
		else if(word <= p->info)
		{
			ListNode* temp = new ListNode(word, head);
			head = temp;
		}
		else
		{
			while(p != nullptr)
			{
				if(word > p->info && p->next == nullptr)
				{
					ListNode* temp = new ListNode(word,p->next);
					p->next = temp;
					
				}
				else if(word > p->info && word <= p->next->info)
				{
					ListNode* temp = new ListNode(word, p->next);
					p->next = temp;
				}	
				p = p->next;
				
			}
		}	
		
	}

	bool find(string word)// O(N)
	{
		ListNode* temp;
		temp = ListNode::find(word, head);
		if(temp)
		{
			return 1;
		}
		return 0;
	}

	void remove(string word)// O(N)
	{	
		head = ListNode::remove(word, head);
	}	

	void print(ostream & out)//O(N)
	{
		for(ListNode* p = head; p != nullptr; p = p->next)
		{
			out << p->info << endl;
		}
		
	}
	
	
	~SortedLinkedList()//O(N)
	{
		while(head != nullptr)
		{
			ListNode* next = head->next;
			delete head;
			head = next;
		}
	}
};
