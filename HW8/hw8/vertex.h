#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include "edge.h"
#include <iostream>
#include <fstream>
using namespace std;
class Vertex
{
public:
	int id;
	std::vector<Edge> edges;
	
	Vertex(int i);

	Vertex();
	
	void add_edge(const Edge& e);
	
	void print(ostream& out);
};

#endif
