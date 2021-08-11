using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "graph.h"
#include "priorityqueue.h"


struct Verts
{
	int id;
	int dist;
	int prev;
};

void dijkstras(Graph& g, int src, Verts* items)
//Big-Oh = O(N^2)
{
	PriorityQueue<Verts> Q(g.num_vertex);
	for(int i = 0; i < g.num_vertex; ++i)
	{
		items[i].id = g.vertices[i]->id;
		items[i].dist = 10000000;
		items[i].prev = -1;
		Q.enqueue(items[i]);
	}
	items[src].dist = 0;
	Q.setFrontZero(src);
	while(!Q.isEmpty())
	{
		
		Verts thing = Q.dequeue();
		int id = thing.id;
		for(auto some: g.vertices[id]->edges)
		{
			int v = some.dst;
			if(items[v].dist > items[id].dist + some.weight)
			{
				items[v].dist = items[id].dist + some.weight;
				items[v].prev = id;
				Q.decreaseKey(v, items[v].dist );
			}
		}
	}
}	

int main(int argc, char* argv[])
{
	string file;
	int source;
        if(argc == 1)
        {
              	cout << "ERROR: FILE INPUT REQUIRED" << endl;
               	return 0;
       	}
       	else if(argc == 2)
       	{
              	cout << "ERROR: FILE INPUT REQUIRED" << endl;
               	return 0;
        }
       	else if(argc == 3)
       	{
		source = std::atoi(argv[1]);
		
       	        file = argv[2];
       	}
       	else if(argc == 4)
	{
		source = std::atoi(argv[2]);
		
		file = argv[3];
	}
	else
       	{
       	        cout << "This shouldnt print" << endl;
       	        return 0;
       	}
					
	//string file = "large.graph";
	Graph g(file);
//	int* dist = new int[g.num_vertex];
//	int* prev = new int[g.num_vertex];

	Verts* items = new Verts[g.num_vertex];	

	dijkstras(g, source, items);

	for(int i = 0; i < g.num_vertex; ++i)
	{
		cout << "id " << items[i].id << ", dist "<< items[i].dist << ", prev " << items[i].prev  << endl;
	}
	delete[] items;
	
	return 0;
}

