#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED

#include <iostream>
#include "Edge.h"

template<class T> class Vertex
{
	private:
		T data;


	public:
		Vertex(T &_data)
		{
			data = _data;
		}
		~Vertex()
		{}

		const T &getData() const
		{
			return data;
		}

		bool operator==(const Vertex &_ver) const
		{
			return getData() == _ver.getData();
		}
		bool operator!=(const Vertex &_ver) const
		{
			return !(*this == _ver);
		}

};



#endif //VERTEX_H_INCLUDED