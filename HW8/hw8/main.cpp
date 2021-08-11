
using namespace std;
#include "graph.h"
#include "vertex.h"
#include "edge.h"
#include <vector>
#include <queue>
struct SetNode
{
	SetNode(): parent(this), id(0), rank(0), size(0) {}
	SetNode* parent;
	int id;
	int rank;
	int size;
};

struct Set
{
	int count;
	SetNode* elements;
	
	Set(int N): count(N), elements(new SetNode[N])
	{
	}
	
	void error(const char* msg)
	//Big-Oh = O(1)
	{
		cerr<< "ERROR: " << msg <<endl;
		exit(-1);
	}

	void verify_set_id(int x)
	//Big-Oh = O(1)
	{
		if(x<0 || x>=count)
		{
			error("ID out of bounds");
		}
	}
	
	void MakeSet(int x)
	//Big-Oh = O(1)
	{
		verify_set_id(x);
		SetNode& my_node = elements[x];
		
		my_node.parent = &my_node;
		my_node.rank = 0;
		my_node.size = 1;
	}

	SetNode* Find(SetNode* x)
	//Big-Oh = O(1)
	{
		if(x->parent != x)
		{
			x->parent = Find(x->parent);
		}
		return x->parent;
	}
	
	SetNode* Find(int x)
	//Big-Oh = O(1)
	{
		verify_set_id(x);
		SetNode& my_node = elements[x];
		return Find(&my_node);
	}

	void Union(int x, int y)
	//Big-Oh = O(1)
	{
		SetNode* xRoot = Find(x);
		SetNode* yRoot = Find(y);
		if(xRoot == yRoot)
		{
			return;
		}
	if(xRoot->size < yRoot->size)
		{
			swap(xRoot, yRoot);
		}
		yRoot->parent = xRoot;
		xRoot->size = xRoot->size + yRoot->size;
	}

	~Set()
	{
		delete[] elements;
	}
};

void make_all_sets(Set& a, int N)
{
	for(int i = 0; i < N; ++i)
	{
		a.MakeSet(i);
	}
}
	
void find_all_sets(Set& a, int N)
{
	for(int i = 0; i < N; ++i)
	{
		cout << i << " set is " << a.Find(i) << endl;
	}
}
	
void union_all_sets(Set& a, int N)
{
	for(int i = 0; i < N; ++i)
	{
		a.Union(0, i);
	}
}
	
void print_sets(Set& a, int N)
{
	for(int i = 0; i < N; ++i)
	{
		cout << i << " set is " << a.Find(i) << endl;
	}
}

class MyCompare
{
public:
	template<typename T>
	bool operator()(T a, T b)
	//Big-Oh = O(1)
	{
		return a.weight >  b.weight;
	}
};
	


vector<Edge> Kruskals(const Graph& g)
//Big-Oh = O(N)
{
	Set s(g.num_edge);
	for(int i = 0; i < g.num_vertex; ++i)
	{
		s.MakeSet(g.vertices[i].id);
	}
	unsigned int N = g.num_vertex;
	priority_queue <Edge, vector<Edge>, MyCompare> Q;
	for(auto e: g.vertices->edges)
	{
		Q.push(e);
	}
	vector<Edge> T;
	while(T.size() < N-1)
	{
		Edge e = Q.top();
		Q.pop();
		if(s.Find(e.src) != s.Find(e.dst))
		{
			T.push_back(e);
			s.Union(e.src, e.dst);
		}
	}
	return T;
}



int main(int argc, char* argv[])
{
	string file;
	if(argc == 1)
	{
		cout << "ERROR: FILE INPUT REQUIRED" << endl;
		return 0;
	} 
	else if(argc == 2)
	{
		file = argv[1];	
	}
	else if(argc == 3)
	{
		file = argv[2];
	}
	else
	{
		cout << "This shouldnt print" << endl;
		return 0;
	}

	Graph g(file);
	vector<Edge> result = Kruskals(g);

	int total_weight = 0;

	for(auto some: result)
	{	
		total_weight = total_weight + some.weight;	
	}
	cout << "Total Weight: " << total_weight << endl;
	for(auto some: result)
	{	
		cout << "[" << some.src << "-" << some.dst << "]" <<
		"(" << some.weight << ")" << endl;
		total_weight = total_weight + some.weight;	
	}


	return 0;
}

