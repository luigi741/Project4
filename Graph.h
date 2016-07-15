#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

/*#include <string>
#include <fstream>
#include <sstream>
#include <map>*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Vertex.h"
//#include "AdjListNode.h"
#include "Edge.h"

using namespace std;

//template<class Type> class Vertex;

template <class Type> class Graph
{
private:
	Edge<Type> *array; //stores the vertices in HashTable/AdjList
	int graphSize; //?
	int size; //number of vertrices in the graph
	int num_edges; //number of egdes in a graph

	int hash(string name)
	{
		int hash = 0;
		int index;
		for (int i = 0; i < name.length(); i++)
		{
			hash = (hash + name[i]) * 2;
		}
		index = hash % graphSize;
		return index;
	}

public:
	Graph(int n):size(0), num_edges(0)
	{
		if(n <= 0)
		{
			n = 25;
			graphSize = n;
		}
		else 
		{
			graphSize = n;
		}

		array = new Edge <Type> [graphSize];

		//HashTable vertrices(graphSize);
	}

	//Destructor
	~Graph()
	{
		delete [] array;
	}

	/**************************************ACCESSORS**********************************************/

	bool empty(){
		return size == 0;
	}

	//returns the degree of a vertex
	int degree(const string &name)
	{
		int deg;

		for (int i = 0; i < graphSize; ++i)
		{
			if(array[i].head->getName() == name){
				deg = array[i].Size();

				return deg-1;
			}
		}
	}

	//returns number of edges in the graph
	int edgeCount(){
		return num_edges;
	}

	//returns true if all vertrices are connected
	bool isConnected(){
		return num_edges == graphSize - 1;	
	}

	//finds the vertex with the same name and returns the data
	Type find_Vertex(const string &name)
	{
		for (int i = 0; i < graphSize; ++i)
		{
			if(array[i].head->getName() == name)
			{
				return array[i].head->getData();
			}
		}
	}

	Vertex<Type>* findVertex(const string &name)
	{
		for (int i = 0; i < graphSize; ++i)
		{
			if(array[i].head->getName() == name)
			{
				return array[i].head;
			}

		}
	}

	//returns the weight of the edge between the two vertices
	double adjacent(string u, string v)
	{
		int index = hash(u);

		if(u == v){
			return 0;
		}
		else if(array[index].find_Node(v) == false){
			return 999.999; //infinity
		}
		else{
			return array[index].weightofEdge(v);
		}
	}

	/*//Performs BFS traversal starting on vertex v. Reset vertices after the traversal
	void DFS(string v)
	{

	}

	//Performs BFS traversal starting on vertex v. Reset vertices after the traversal.
	void BFS(string v)
	{

	}
*/
	Vertex<Type>* min(Vertex<Type>* num, Vertex<Type>* num1)
	{
		if(num->weight > num1->weight)
		{
			return num1;
		}
		return num;
	}

	Vertex<Type>* minWeight(const string _name)
	{
		int index = hash(_name);
		Vertex<Type>* minimo;

		Vertex<Type>* ptr = array[index].head;
		Vertex<Type>* ptrNext = ptr->next;

		//pick the minimum weight
		while(ptrNext != NULL)
		{
			if(ptr->visited)
			{
				ptr = ptr->next;
			}
			//cout << "DEBUG1" << endl;
			/*while(ptr->getVisited())
			{
				ptr = ptr->next;
			}*/
			//cout << "DEBUG2" << endl;
			minimo = ptr;
			minimo =  Graph::min(minimo, ptrNext);

			ptr = ptr->getNext();
			ptrNext = ptrNext->getNext();
		}
		return minimo;
	}

	//Returns the minimum spanning tree of those vertices which are connected to vertex v. 
	//Throw an illegal argument exception if the arguments do not correspond to existing vertices.
	void MST(string v)
	{
		Vertex<Type>* mst;
		Vertex<Type>* minW;

		//prims algorithm
		int index = hash(v);


		//Set all Vertex->visited to false, except v's
		for(int i = 0; i < graphSize; i++)
		{
			mst = array[i].head;
			while(mst->getNext() != NULL)
			{
				mst->setVisitedFalse();
				mst = mst->getNext();
			}
		}

		mst = findVertex(v);
		//set start->visited true
		mst->setVisitedTrue();
		//Find minimum path
		cout << "Root: " << mst->name << endl;
		for(int i = 0; i < size; i++)
		{
			minW = minWeight(mst->getName());
			minW->setVisitedTrue();
			cout << i+1 << ": " << minW->name << endl;
			mst = minW;
		}
		


	}

	void printGraph()
	{
		cout << "PRINT GRAPH" << endl;
		for (int i = 0; i < graphSize; ++i)
		{
			
			cout << "Vertex ";
			array[i].Head();

			cout << endl;

			cout << "Adjacent Vertices: ";
			array[i].printList();
			cout << endl;
		}
	}

	/**************************************MUTATORS**********************************************/

	//adds the vertex to the graph and stores it into a hash table
	void addVertex(const string &name, const Type &data)
	{
		int index = hash(name);

		array[index].insert(name, data);
		
		size++;
	}

	//adds an edge between two vertices; if one of the vertex dosent exist error;
	//if src and st is the same error; if weight is 0 delete edge if there is one;
	//if edge already exist update weight
	void addEdge(const string &src, const string &dst, const double &weight)
	{
		int index1 = hash(src);
		int index2 = hash(dst);

		if(array[index1].head == NULL || array[index2].head == NULL){
			cout << "One of these vertices doesn't exist." << endl;
		}

		else if(index1 == index2){
			cout << "Illegal. Same vertex" << endl;
		}

		else if(weight == 0) {
			if(array[index1].find_Node(dst)){
				array[index1].del(dst);
				array[index2].del(src);

				num_edges--;
			}
		}

		else{
			if(array[index1].find_Node(dst)){
				array[index1].changeWeight(dst, weight);
				array[index2].changeWeight(src, weight);
			}
			else{
				Type data1 = find_Vertex(src);
				Type data2 = find_Vertex(dst);

				array[index1].insert(dst, data2, weight);
				array[index2].insert(src, data1, weight);
			
				num_edges++;
			}
		}
	}

	/*//Reads structure from a text file and builds a undirected weighted graph.
	void buildGraph()
	{

	}

	//Removes all the elements in the undirected weighted
	void clear()
	{

	}
	*/
	//Iterates over all vertices in the graph and marks them as unvisited.
	void reset()
	{
		
	}
};

#endif