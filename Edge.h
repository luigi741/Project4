#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include <iostream>
#include <string>
#include "Vertex.h"

using namespace std;

class Vertex;

class Edge
{
	private:
		Vertex* TwoEdges; //For undirected graph

	public:
		Edge(): TwoEdges(NULL)
		{}
		~Edge(){}

		Vertex* get_Vertices()
		{
			return TwoEdges;
		}
};



#endif //3EDGE_H_INCLUDED