/*#include "Graph.h"
#include "DirGraph.h"
#include "Vertex.h"
#include "Edge.h"*/

#include <iostream>
#include <string>
#include "Vertex.h"
#include "HashTable.h"

using namespace std;


int main() 
{
	int opCode = 0;
	cout << "****Testing HashTable****" << endl;
	cout << "Initiate array of LL." << endl;

	HashTable<Vertex<string> > Table = HashTable<Vertex<string> >(5);


	
	while(true)
	{
		cout << "**************" << endl;
		cout << "Hash Functions" << endl;
		cout << "0. Quit" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Display" << endl;
		cout << "-->";
		cin >> opCode;

		cout << "Hello" << endl;
		if(opCode == 0)
		{
			return 0;
		}

		switch(opCode)
		{
			case 1:
			{
				string data;
				while(data != "0")
				{
					cout << "*****Insert*****" << endl;
					cout << "~Enter \'0\' to exit" << endl;
					cout << "Data(string) to insert: ";
					cin >> data;

					if(data == "0") break;

					Vertex<string>* vertex = new Vertex<string>(data);	
					bool insert;
					//cout << "DEBUG:: going into Insert()" << endl;
					insert = Table.Insert(vertex);
				}
	
				break;
			}

			case 2:
			{
				cout << "*****CURRENT TABLE*****" << endl;

				Table.printTable();
				break;
			}
		}	

	}
		
	
	
	
}