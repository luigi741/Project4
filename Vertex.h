#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <iostream>
#include "Edge.h"

template<class Type> class Vertex
{
	private:
		Type data;


	public:
		Vertex(Type _data)
		{
			data = _data;
		}
		~Vertex()
		{}

		Type get_Data()
		{
			return data;
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