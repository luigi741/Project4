#ifndef PRIMSALGORITHM_H_INCLUDED
#define PRIMSALGORITHM_H_INCLUDED

#include <iostream>
using namespace std;

class PrimsAlgorithm {
private:
	// Members
public:
	// Constructor
	PrimsAlgorithm(int n = 20) {}

	// Destructor
	~PrimsAlgorithm() {}

	// Returns TRUE if the graph is empty, FALSE otherwise
	bool empty() const 
	{

	}

	// Returns the degree of the vertex v. Throw an illegal exception
	// if the argument does not correspond to an existing vertex
	int degree(string v) {

	}

	// Returns the number of edges of the vertex v
	int edgeCount(string v) {

	}

	// Returns the number of edges in the graph
	int edgeCount() {

	}

	// Determines if the graph is connected
	bool isConnected() {

	}

	// Returns the weight of the edge connecting vertices u and v. If the
	// vertices are not adjacent, return infinity (your represenation of it)
	// Throw an illegal argument exception if the arguments don't correspond
	// to existing vertices
	double adjacent (string u, string v) {

	}

	// Performs Depth First Search traversal starting on vertex v. Reset
	// vertices after the traversal
	void DFS(string v) {

	}

	// Performs Depth First Search starting on vertex v. Reset vertices
	// after the traversal
	void BFS(string v) {

	}

	// Returns the Minimum Spanning Tree of those vertices which are connected
	// vertex v. Throw an illegal argument exception if the arguments don't
	// correspond to existing vertices
	void MST(string v) {

	}

	// Reads structure from a text file and builds an undirected weighted graph
	void buildGraph() {

	}

	// Removes all the elements in the undirected weighted graph
	void clear() {

	}

	// Iterates over all vertices in the graph and marks them as unvisited
	void reset() {

	}

	// If the weight w < 0 or if w = infinity, throw an illegal argument exception.
	// If the weight w = 0, remove any edge between u and v (if any). Otherwise,
	// add an edge b/t vertices u and v with weigh w. If an edge already exists,
	// replace the weight of the edge with the new weight. If the vertices don't
	// exist or are equal, throw an illegal argument exception
	void insert() {

	}

	// Removes vertex v from the graph and updates connections in the graph
	void deleteVertex(string v) {

	}

};

#endif