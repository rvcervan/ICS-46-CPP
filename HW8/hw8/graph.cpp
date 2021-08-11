#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Graph::Graph(string file_name)
	:num_edge(0)
{
	ifstream in(file_name);
	in>>num_vertex;
	vertices = new Vertex[num_vertex];
	int source, dest, weight;
	while(in>>source && in>>dest && in>>weight)
	{
		//cout << source << " " << dest << " " << weight << endl;
		add_edge(source, dest, weight);
	}
	
}

void Graph::add_edge(int src, int dst, int w)
{
	Edge* edge = new Edge(src, dst, w);
	++num_edge;
	vertices->add_edge(*edge);
	delete edge;
}

void Graph::print(ostream& out)
{
	out << "vertices: " << num_vertex << endl;
	out << "edges:    " << num_edge << endl;
	out << endl;
	out << "In vertices array" << endl;
	for(int i = 0; i < num_vertex; ++i)
	{
		out << vertices[i].id << endl;
	}
}



Graph::~Graph()
{
	delete[] vertices;
}
