#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include <iostream>
#include "Vertex.h"

using namespace std;

template <class Type> class Graph;
template <class Type> class Vertex;

template <class Type> class Edge
{
friend class Graph <Type>;
private:
	Vertex <Type> *head;
	Vertex <Type> *tail;
	int size;
public:
	Edge(): head(NULL), tail(NULL), size(0)
	{}
		
	~Edge()
	{
		Vertex <Type> *current = head;
	
		for(int i = 0; i < size; i++){
			Vertex <Type> *n = current->getNext();
			delete current;
			current = n;
		}
	
		head = NULL;
		tail = NULL;
		size = 0;
	}
		
	int Size() const {
		return size;
	}
		
	bool empty() const {
		if(head == NULL){
			return true;
		}
		else{
			return false;
		}
	}
		
	void Head() const {
		if(empty() == true){
			throw underflow_error("List empty. Cannot retrieve head object.\n");
		}
		else{
			cout << head->getName() << ", ";
			cout << "Data " << head->getData() << ": ";
		}
	}
		
	Vertex <Type> *Tail() const {
		if(empty() == true){
			throw underflow_error("List empty. Cannot retrieve tail object.\n");
		}
		else{
			return tail;
		}
	}
	
	int count (const string &name) const{
		Vertex <Type> *current = head;
		int nodes = 0;
		
		while(current != NULL){
            
			if(current->name == name){
				nodes++;
            }
			
            current = current->next;
		}
		
		return nodes;
	}
		
	void insert(const string &name, const Type &data)
	{
		Vertex <Type> *new_node;
	
		if(empty() == true){
			new_node = new Vertex <Type> (name, data, 0.0);
			head = new_node;
			tail = new_node;
		}
		else{
			new_node = new Vertex <Type> (name, data, 0.0);
			
			tail->next = new_node;
			
			tail = new_node;
		}
	
		size++;
	}

	void insert(const string &name, const Type &data, const double &weight)
	{
		Vertex <Type> *new_node;
	
		if(empty() == true){
			new_node = new Vertex <Type> (name, data, weight);
			head = new_node;
			tail = new_node;
		}
		else{
			new_node = new Vertex <Type> (name, data, weight);
			
			tail->next = new_node;
			
			tail = new_node;
		}
	
		size++;
	}
		
	void del (const string & name)
	{	
		Vertex <Type> *current = head;
        Vertex <Type> *prev = head;

		if(empty() == true){
			throw underflow_error("List is empty. Cannot retrieve tail object.\n");
		}
		else{
			while(current != NULL) {
				if(current->name == name) {	
					if(current == head){
						head = current->next;
					} 
					else if(current == tail){
						tail = prev;
						tail->next = NULL;
					}
					else{
						prev->next = current->next;
						current = prev;
					}

					size--;
					return ;
				}
				
				else {
					prev = current;
					current = current->next;
				}
			}
		}
	}
	
	bool find_Node (const string & name)
	{	
		Vertex <Type> *current = head;

		while(current != NULL) {
			if(current->name == name) {
				return true;
			}		
			else {
				current = current->next;
			}
		}
	}

	void changeWeight(string name, double weight)
	{
		Vertex <Type> *current = head;

		while(current != NULL) {
			if(current->name == name) {
				current->weight = weight;

				return ;
			}	
			else {
				current = current->next;
			}
		}
	}

	double weightofEdge(string name)
	{
		Vertex <Type> *current = head;

		while(current != NULL) {
			if(current->name == name) {
				return current->getWeight();
			}	
			else {
				current = current->next;
			}
		}
	}
		
	void printList()
	{
		Vertex <Type> *current = head->next;
	
		while(current != NULL){
			cout << "("<< current->getName();
			cout << " , " << current->getWeight() << ") ";
			
			current = current->next;
		}
	}
};

#endif