#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <iostream>
#include <vector>
#include <list>
#include "Edge.h"

//Vector
/*
-->resize()
-->size()
-->begin()
-->end()
--
*/


//List
/*
-->clear()
--> ::iterator
-->

*/


using namespace std;

template<class HashObj> class HashTable
{
	private:
		int currentSize;
		vector<list<HashObj>> Table; 

		void ReHash()
		{
			vector<list<HashObj>> oldTable = Table;

			//new table double size
			Table.resize(nextPrime(2 * Table.size())); 
			for(int i = 0; i < Table.size(); i++)
			{
				Table[i].clear(); 
			}

			//copy old table
			currentSize = 0;
			for(int i = 0; i < Table.size(); i++)
			{
				list<HashObj>::iterator iter = oldTable[i].begin();
				while(iter != oldTable[i].end())
				{
					Insert(*iter++);
				}
			}

		}

		int MyHash(const string& _key) const
		{
			int hashV = hash(_key);

			hashV %= Table.size(); 
			if(hashV < 0)
			{
				hashV += Table.size(); 
			}

			return hashV;
		};

	public:
		HashTable(int size)
		{
			//
		}

		bool Contains(const HashObj &x);

		void Clear()
		{
			for(int i = 0; i < list.size(); i++) // list ###
			{
				Table.clear(); // list ###
			}
		}

		bool Insert(const HashObj &x)
		{
			//O(n) in the length of the list at the hashed bucket.
			list<HashObj> &list = Table[MyHash(x)];
			if(find(list.begin(), list.end(), x) != list.end()) // list ###
			{
				return false;
			}
			list.push_back(x); //list ###

			//Rehashing
			if(++currentSize > Table.size()) //list ###
			{
				ReHash();
			}
			return true;
		}


		bool Remove(const HashObj& x)
		{
			list<HashObj> &list = Table[MyHash(x)];

			list<HashObj>::iterator iter = find(list.begin(), list.end(), x); // list ###

			if(iter == list.end()) // list ###
			{
				return false;
			}

			list.erase(iter); // list ###
			--currentSize;
			return true;
		}
};

#endif //HASHTABLE_H_INCLUDED