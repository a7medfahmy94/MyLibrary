#include <stdio.h>
#include <assert.h>
#include <vector>
#include "Graph.h"
#include "DFS.h"
#include "BFS.h"
#include "ConnectedComponent.h"

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

	printf("passed!\n================\n");
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

	printf("passed!\n================\n");
}

void testBFS(){
	printf("Testing BFS\n");

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

	BFS bfs(g , 2);

	assert(bfs.isConnectedTo(0) == false);
	printf("2 is not connected to 0\n");

	assert(bfs.isConnectedTo(8) == true);
	printf("2 is connected to 8\n");

	assert(bfs.distanceTo(8) == 2);
	printf("distance from 2 to 8 is 2\n");

	assert(bfs.distanceTo(5) == 3);
	printf("distance from 2 to 5 is 3\n");

	printf("passed!\n================\n");
}

void testConnectedComponent(){
	printf("Testing ConnectedComponent\n");

	Graph g(10);
	g.addUnweightedEdge(0 , 1, true);
	g.addUnweightedEdge(2 , 1, true);

	g.addUnweightedEdge(3 , 4, true);
	g.addUnweightedEdge(4 , 5, true);
	g.addUnweightedEdge(6 , 5, true);

	g.addUnweightedEdge(7 , 8, true);
	g.addUnweightedEdge(9 , 7, true);

	ConnectedComponent cc(g);

	assert(cc.sameComponent(0 , 1));
	assert(cc.sameComponent(0 , 2));
	printf("0,1,2 are a connected component\n");

	assert(cc.sameComponent(3 , 4));
	assert(cc.sameComponent(5 , 4));
	assert(cc.sameComponent(5 , 6));
	printf("3,4,5,6 are a connected component\n");

	assert(cc.sameComponent(7 , 8));
	assert(cc.sameComponent(7 , 9));
	printf("7,8,9 are a connected component\n");

	assert(cc.sameComponent(7 , 0) == false);
	printf("0,7 are not connected\n");

	assert(cc.sameComponent(7 , 3) == false);
	printf("7,3 are not connected\n");

	assert(cc.sameComponent(1 , 6) == false);
	printf("1,6 are not connected\n");


	printf("passed!\n================\n");

}

int main(){
	testGraph();
	testDFS();
	testBFS();
	testConnectedComponent();

	printf("All Passed!!!\n");
}