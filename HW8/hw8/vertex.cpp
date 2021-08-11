using namespace std;
#include <string>
#include "vertex.h"
#include <iostream>
#include <vector>
#include "edge.h"
#include <fstream>

Vertex::Vertex(int i)
	: id{i} {}

Vertex::Vertex()
	: id{0} {}

void Vertex::add_edge(const Edge& e)
{
	edges.push_back(e);
}

void Vertex::print(ostream& out)
{
	out << "vertex ID: " << id << endl;
	out << "vector contents" << endl;
	for(auto i: edges)
	{
		out << i.src << " " << i.dst << " " << i.weight << endl;
	}
}
