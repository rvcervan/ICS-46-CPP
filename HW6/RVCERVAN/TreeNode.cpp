using namespace std;
#include <iostream>
#include <string>
#include <map>
#include <iterator>
template <typename KeyType, typename ElementType>

class SearchTree
{

	struct TreeNode{
		KeyType key;
		ElementType info;
		TreeNode* left, * right;
		//int nodesCreated = 0;
		TreeNode(KeyType new_key, ElementType new_info, TreeNode* new_left, TreeNode* new_right)
			:key(new_key), info(new_info), left(new_left), right(new_right) {}
	
		TreeNode(const TreeNode& tn) = delete;
	
		TreeNode& operator = (const TreeNode& tn) = delete;
	
		static int count_nodes(TreeNode* t)
		{
			return t==nullptr?0:1+count_nodes(t->left)+count_nodes(t->right);
		}

	

		static TreeNode* newNode(KeyType k, ElementType e, TreeNode* l, TreeNode* r)
		//T(N) = 1001
		//Big-O = O(1)
		{
		//	++nodesCreated;
			return new TreeNode(k,e,l,r);
		}
	
		static TreeNode* insert(KeyType key, ElementType info, TreeNode* RootT)
		//T(N) = 2014N + 1005
		//Big-O = O(N)
		{
			if(!RootT)
			{
				RootT = newNode(key, info, nullptr, nullptr);//1002
				return RootT;//1
			}
			TreeNode* t = RootT;//1
			while(t->key != key)//N
			{
				if(key < t->key)//N
				{
					if(!t->left)//N
					{
						t->left = newNode(key, info, nullptr, nullptr);//1002N
						return RootT;//N
					}
					t = t->left;//N
				}
				else if(key > t->key)//N
				{
					if(!t->right)//N
					{
						t->right = newNode(key, info, nullptr, nullptr);//1002N
						return RootT;//N
					}
					t = t->right;//N
				}
				t->info = info;//N
			}
			return RootT;//1
		}
	
		static TreeNode* find(KeyType key, TreeNode* t)
		//T(N) = 6N + 2
		//Big-O = O(N)
		{
			TreeNode* temp = t;//1
			while(temp!=nullptr)//N
			{
				if(key < temp->key)//N
				{
					temp = temp->left;//N
				}
				else if(key > temp->key)//N
				{
					temp = temp->right;//N
	
				}
				else
				{
					return temp;//N
					
				
				}
			}
			return nullptr;//1
		}
	
		static TreeNode* findPred( TreeNode* t)
		//T(N) = 2N + 3
		//Big-O = O(N)
		{	
			TreeNode* tn = t;//1
			tn = tn->left;//1
			while(tn->right != nullptr)//N
			{
				tn = tn->right;//N
			}
			return tn;//1
		}
		
		static TreeNode* findSucc(TreeNode* t)
		//T(N) = 2N + 3
		//Big-O = O(N)
		{
			TreeNode* tn = t;//1
			tn = tn->right;//1
			while(tn->left != nullptr)//N
			{
				tn = tn->left;//N
			}
			return tn;//1
		}

		static void swapKeyAndInfo(TreeNode* predNode, TreeNode* toRemove)
		//T(N) = 6
		//Big-O = O(1)
		{
			KeyType tempkey;
			ElementType tempinfo;
	
			tempkey = predNode->key;
			tempinfo = predNode->info;
	
			predNode->key = toRemove->key;
			predNode->info = toRemove->info;
	
			toRemove->key = tempkey;
			toRemove->info = tempinfo;
		}	
		
		static TreeNode* remove(KeyType key, TreeNode* t)
		//Big-O = O(N)
		{
			TreeNode* toRemove = find(key, t);
			if(toRemove == nullptr)
			{
				return nullptr;
			}
			else if(toRemove->left == nullptr)
			{
				if(toRemove->right == nullptr)
				{
					return t;
				}
				else
				{
					TreeNode* succ = findSucc(toRemove);
					swap(succ->info,toRemove->info);
					swap(succ->key,toRemove->key);
					return t;
				}
			}
			else if(toRemove->right == nullptr)
			{
				TreeNode* pred = findPred(toRemove);
				swapKeyAndInfo(pred, toRemove);
				return t;

			}
			else
			{
				TreeNode* predecessorNode = findPred(toRemove);
				swapKeyAndInfo(predecessorNode, toRemove);
				toRemove = remove(key, toRemove);
				return t;
			}
			return nullptr;
		}
		
		static void print(ostream& out, TreeNode* t)
		//Big-O = O(N)
		{
			if(t)
			{
				out << '[';
				print(out, t->left);
				out << '(' << t->key << ',' << t->info << ')';
				print(out, t->right);
				out << ']';
			}
			else
			{
				out << "nullptr";
			}
		}
		
		static void deleteNode(TreeNode* t)
		//T(N) = 1
		//Big-O = O(1)
		{
		//	--nodesCreated;
			delete t;
		}
		
		static void deleteTree(TreeNode* t)
		//Big-O = O(1)
		{
			if(t)
			{
				deleteTree(t->left);
				deleteTree(t->right);
				deleteNode(t);
			}
		}
	};
	
	TreeNode* root;
public	:
	SearchTree()
		: root(nullptr)
	{
	}
	
	map<int, int> countLength;

	SearchTree(const SearchTree& st) = delete;

	SearchTree& operator = (const SearchTree& st) = delete;

	int& operator[](KeyType key)
	//T(N) = 8N + 3
	//Big-O = O(N)
	{
		TreeNode* temp = TreeNode::find(key, root);//6N + 2
		if(temp != nullptr)//N
		{
			return temp->info;//N	
		}
		throw;//1
	}

	void insert(KeyType s, ElementType c)
	//T(N) = 3015N + 2005
	//Big-O = O(N)
	{
		countLength[s.size()]++;//1001N + 1000
		root = TreeNode::insert(s, c, root);//2014N + 1005
	}
	
	bool find(KeyType s)
	//T(N) = 6N + 4
	//Big-O = 2
	{
		TreeNode* temp;
		temp = TreeNode::find(s, root);//6N + 2

		if(temp)
		{
			return 1;//1
		}
		return 0;//1
	}

	void countLengths()
	//T(N) = 1001N + 1000
	//Big-O = O(N)
	{
		map<int, int>::iterator it;//1000
		for(auto const& c : countLength)//N
		{
			cout<<"length "<<c.first<<": "<<c.second<<" words"<<endl;//1000N
		}
	}
	
	void remove(KeyType s)
	//Big-O = O(N)
	{
		root = TreeNode::remove(s, root);
	}
	
	void count()
	{
		cout << TreeNode::count_nodes(root) << endl;
	}
	
	~SearchTree()
	{
		TreeNode::deleteTree(root);
	}
	
};
