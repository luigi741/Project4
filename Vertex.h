#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <iostream>

using namespace std;

template <class Type> class Graph;
template <class Type> class Edge;

template <class Type> class Vertex
{
friend class Edge<Type>;
friend class Graph<Type>;
private:
	string name;
	Type data;
	double weight;
	bool visited;

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

	void setVisitedTrue()
	{
		this->visited == true;
	}
	
	void setVisitedFalse(){
		this->visited = false;
	}

	Vertex *getNext() const{
		return this->next;
	}
};

#endif //VERTEX_H_INCLUDED