#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Vertex.h"
#include "Edge.h"
#include "LinkList.h"

//Vector
/*
-->resize()
-->size()
-->begin()
-->end()
--



//List

-->clear()
--> ::iterator
--> pushback
-->

*/


using namespace std;


template<class Type> class HashTable
{
	private:
		int currentSize;
		//vector<list<Type>> Table;
		LinkList<Type>* Table[]; 

		/*void ReHash()
		{
			//First set a ew table equal to our current table
			//2. Double the current Table size
			//3. Clear the current table.
			//4. insert values from oldTable into newTable.
			
			//vector<list<Type>> oldTable = Table;
			
			LinkList<Type>* oldTable[] = nTable;

			//nTable.

			Table.resize(nextPrime(2 * Table.size())); 
			for(int i = 0; i < Table.size(); i++)
			{
				Table[i].clear(); 
			}

			//copy old table
			currentSize = 0;
			for(int i = 0; i < Table.size(); i++)
			{
				list<Type>::iterator iter = oldTable[i].begin();
				while(iter != oldTable[i].end())
				{
					Insert(*iter++);
				}
			}

		}*/

		int MyHash(string _key) const 
		{
			//Using the second letter of the key to the word.
			int i = 0;
			int hashV;

			while(i < _key.length())
			{
				hashV += _key[i];
				i++;
			}
			

			hashV %= currentSize; 

			return hashV;
		};

	public:
		HashTable(int _size)
		{
			currentSize = _size;
			for(int i = 0; i < currentSize; i++)
			{
				Table[i] = NULL;
			}
		}

		~HashTable(){}

		/*bool Contains(const Type &x);

		void Clear()
		{
			for(int i = 0; i < list.size(); i++) // list ###
			{
				Table.clear(); // list ###
			}
		}
		*/

		bool Insert(Type* _vertex)
		{
			//O(n) in the length of the list at the hashed bucket.

			int index = MyHash(_vertex->get_Data());

			if(Table[index] == NULL)
			{
				LinkList<Type>* list = Table[index];
				list = new LinkList<Type>;
			}

			LinkList<Type>* list = Table[index];
			bool l = Table[index].is_Empty();
			cout << l;

			//CRASHING AFTER 3 INPUTS MAYBE NEED TO ACCOUNT FOR WHEN 
			//LIST != null?
			cout << "HashIndex: " << MyHash(_vertex->get_Data()) << endl;
			cout << "Debug1" << endl;
			list->add_node(_vertex->get_Data());
			cout << "Debug2" << endl;

			//Rehashing
			/*if(++currentSize > Table.size()) //list ###
			{
				ReHash();
			}*/
			return true;
		}

/*
		bool Remove(const Type& x)
		{
			list<Type> &list = Table[MyHash(x)];

			list<Type>::iterator iter = find(list.begin(), list.end(), x); // list ###

			if(iter == list.end()) // list ###
			{
				return false;
			}

			list.erase(iter); // list ###
			--currentSize;
			return true;
		}*/

		void printTable()
	    {
	        cout << "The Hash Table has the following entries: " <<endl;
	        cout << "***********************" << endl;

	        int i = 0;

	        while(i < currentSize)
	        {
	            cout << "HashTable[" << i << "]: ";
	            if(Table[i] == NULL)
	            {
	            	Table[i] = new LinkList<Type>();
	            }

	            Table[i]->print_List();
	            i++;
	            cout << endl;
	        }

	        /*cout << "Size: " << this->Size << endl;
	        cout << "Capacity: " << this->Capacity << endl;
	        cout << "Entries: " << this->entries << endl;
	        cout << "loadf : " << this->loadFactor << endl;
	        cout << "************************" << endl;*/
	    }
};

#endif //HASHTABLE_H_INCLUDED