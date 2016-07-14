#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <iostream>

using namespace std;

template <class Type> class Graph;
template <class Type> class Edge;
template <class Type> class Vertex;

struct ActualEdge{
	double edgeWeight;
	Vertex<double>* edgeHead;
	Vertex<double>* edgeTail;
};

template <class Type> class Vertex
{
friend class Edge<Type>;
friend class Graph<Type>;
private:
	string name;
	Type data;
	double weight;
	bool visited;
	ActualEdge* edgeArray;

	Vertex *next;
public:
	Vertex(string name, Type data, double weight): next(NULL), visited(false)
	{
		this->name = name;
		this->data = data;
		this->weight = weight;
	}

	string getName() const{
		return this->name;
	}

	Type getData() const{
		return this->data;
	}
	
	double getWeight() const{
		return this->weight;
	}

	bool getVisited() const{
		return this->visited;
	}

	Vertex *getNext() const{
		return this->next;
	}

	void addEdge()
	{
		if(edgeArray == NULL)
		{
			edgeArray = new ActualEdge;
			return;
		}

	}
};

#endif //VERTEX_H_INCLUDED