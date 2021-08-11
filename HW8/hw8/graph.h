#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "vertex.h"
#include <fstream>
using namespace std;

class Graph
{
public:
	Vertex* vertices;
	
	int num_vertex;
	
	int num_edge;

	Graph(string file_name);
	
	void add_edge(int src, int dst, int w);
	
	void print(ostream& out);
	
	Vertex* array_vertex();

	void print_vertices();
	
	~Graph();
	
	
};
#endif
