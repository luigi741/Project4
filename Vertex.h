#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <iostream>
#include <string>
#include "Edge.h"

using namespace std;

class Edge;

//Type is string
class Vertex
{
	private:
		string name;
		string data;
		Edge* edges;
		bool Visited;


	public:
		Vertex(string _name, string _data)
		{
			name = _name;
			data = _data;
			Visited = false;
		}
		~Vertex()
		{}

		string get_Data()
		{
			return data;
		}

		string get_Name()
		{
			return name;
		}

		bool visited()
		{
			Visited = true;
		}

		bool operator==(const Vertex &_ver) const
		{
			return get_Data() == _ver.get_Data();
		}
		bool operator!=(const Vertex &_ver) const
		{
			return !(*this == _ver);
		}
};



#endif //VERTEX_H_INCLUDED