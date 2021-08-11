#include "edge.h"
#include <iostream>
#include <fstream>
using namespace std;

Edge::Edge(int s, int d, int w)
	: src{s}, dst{d}, weight{w}{}

void Edge::print(ostream& out)
{
	out << "source ID:      " << src << endl;
	out << "destination ID: " << dst << endl;
	out << "edge weight:    " << weight << endl;
}
