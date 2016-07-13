#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include "Edge.h"
#include "Vertex.h"
#include "LinkList.h"

using namespace std;

class Graph 
{
	private:
		LinkList<Vertex>** AdjList;
		int numVertex;
		int numEdge;
		Edge *edge;
		Vertex *vertex;

	public:
		// Constructor
		Graph(int numV): edge(NULL), vertex(NULL)
		{
			numVertex = numV;
		}

		// Destructor
		~Graph() {}

		void buildGraph()
		{
			//READ FROM TEXT FILE
						//Initialize AdjList
			for(int i = 0; i < numVertex; i++)
			{
				AdjList[i] = new LinkList<Vertex>();
				{
					/* data */
				}
			}
		}

		void clear()
		{
			//Delete all vertices
			for(int i = 0; i < numVertex; i++)
			{
				AdjList[i]->del_All();
			}
		}

};

#endif