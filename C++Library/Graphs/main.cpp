#include <stdio.h>
#include <assert.h>
#include <vector>
#include "Graph.h"
#include "DFS.h"

using namespace std;

void testGraph(){
	printf("Testing Graph API\n");

	Graph g(4);
	g.addUnweightedEdge(0,1);//unweighted directed edge
	g.addUnweightedEdge(0,2,true);//unweighted undirected edge
	g.addWeightedEdge(1,2,2.2);//weighted directed edge
	g.addWeightedEdge(1,3,2.5,true);//weighted undirected edge

	assert(g.hasEdge(0,1) == true);
	printf("There is an edge between 0 and 1\n");

	assert(g.hasEdge(0,2) && g.hasEdge(2,0));
	printf("There is an undirected edge between 0 and 2\n");

	assert(g.hasEdge(0,3) == false);
	printf("There is not an edge between 0 and 3\n");

	assert(g.getWeight(0,1) == 0);
	printf("The weight of the edge between 0 and 1 is 0\n");

	assert(g.getWeight(1,2) - 2.2 < 0.0001);
	printf("The weight of the edge between 1 and 2 is 2.2\n");

	printf("All passed!\n================\n");
}

void testDFS(){
	printf("Testing DFS\n");

	Graph g(10);
	g.addUnweightedEdge(0 , 1);
	g.addUnweightedEdge(2 , 1);
	g.addUnweightedEdge(2 , 3);
	g.addUnweightedEdge(2 , 7);
	g.addUnweightedEdge(3 , 4);
	g.addUnweightedEdge(4 , 5);
	g.addUnweightedEdge(6 , 5);
	g.addUnweightedEdge(7 , 4);
	g.addUnweightedEdge(7 , 8);
	g.addUnweightedEdge(9 , 6);
	g.addUnweightedEdge(9 , 7);

	DFS dfs(g , 2);
	vector<int> pathTo_0 = dfs.pathTo(0);
	vector<int> pathTo_4 = dfs.pathTo(4);
	vector<int> pathTo_5 = dfs.pathTo(5);

	assert(dfs.isConnectedTo(0) == false);
	printf("2 is not connected to 0\n");

	assert(dfs.isConnectedTo(8) == true);
	printf("2 is connected to 8\n");

	assert((int)pathTo_0.size() == 0);
	printf("path from 2 to 0 has 0 length\n");

	assert((int)pathTo_4.size() == 2);
	printf("path from 2 to 4 has length of 2\n");
	printf("2-%d-%d\n",pathTo_4[0],pathTo_4[1]);

	assert((int)pathTo_5.size() == 3);
	printf("path from 2 to 5 has length of 3\n");
	printf("2-%d-%d-%d\n",pathTo_5[0],pathTo_5[1],pathTo_5[2]);

	printf("All passed!\n================\n");
}

int main(){
	testGraph();
	testDFS();
}