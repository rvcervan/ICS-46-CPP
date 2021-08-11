#ifndef EDGE_H
#define EDGE_H
#include <iostream>
#include <fstream>
using namespace std;


class Edge
{
public:
	int src;
	
	int dst;
	
	int weight;
	
	Edge(int s, int d, int w);
	
	Edge reverse();
	
	void print(ostream& out);
};
#endif
