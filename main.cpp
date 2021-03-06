/*#include "Graph.h"
#include "DirGraph.h"
#include "Vertex.h"
#include "Edge.h"*/

#include <iostream>
#include <string>
#include <math.h>
#include "Vertex.h"
#include "Graph.h"

using namespace std;


#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	Graph<double> g(5);

	//make sure to fill up the entire table or there will be segmentation faults
	g.addVertex("Bb", 5.78);
	g.addVertex("Cc", 6.5);
	g.addVertex("Dd", 553.98);
	g.addVertex("Ee", 21.21);
	g.addVertex("Ff", 3.98);

	g.addEdge("Bb", "Cc", 2.0);
	g.addEdge("Cc", "Dd", 3.0);
	g.addEdge("Bb", "Dd", 4.0);
	g.addEdge("Ee", "Ff", 5.0);
	g.addEdge("Cc", "Ff", 6.0);

	//g.printGraph();

	g.MST("Bb");

	/*cout << "Is graph Connected " << g.isConnected();
	cout << endl;

	g.addEdge("Dd", "Bb", 89.34);
	g.addEdge("Cc", "Ee", 3.4); //Cc Eel
	
	cout << "Is graph Connected " << g.isConnected();
	cout << endl;

	g.addEdge("Bb", "Bb", 4.20); 
	g.addEdge("Ee", "Ff", 5.09);

	cout << "Is graph Connected " << g.isConnected();
	cout << endl;

	g.addEdge("Cc", "Dd", 0.67);
	g.addEdge("Dd", "Cc", 1.34);

	cout << "Is graph Connected " << g.isConnected();
	cout << endl;

	cout << endl;
	g.printGraph();
	cout << endl;

	cout << "Degree of Vertex Cc: " << g.degree("Cc");
	cout << endl;

	//g.addEdge("Cc", "Ee", 0);
	cout << "CCEE removed?" << endl;
	cout << "Is graph Connected " << g.isConnected();

	cout << endl;

	g.printGraph();
	cout << endl;

	cout << "Degree of Vertex Bb: " << g.degree("Bb");
	cout << endl;

	cout << "Degree of Vertex Cc: " << g.degree("Cc");
	cout << endl;

	cout << "Weight of Edge between Bb and Bb is " << g.adjacent("Bb", "Bb");
	cout << endl;

	cout << "Weight of Edge between Cc and Bb is " << g.adjacent("Cc", "Bb");
	cout << endl;

	cout << "Weight of Edge between Cc and Dd is " << g.adjacent("Cc", "Dd");
	cout << endl;

	
	cout << endl;*/

	//g.printGraph();
	cout << "Initializing Depth First Search starting with 'Bb': " << endl;
	g.DFS("Bb");

	cout << (pow(2, 64) - 1) << endl;

	return 0;
}
