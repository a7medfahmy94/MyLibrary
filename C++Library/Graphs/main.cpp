#include <stdio.h>
#include <assert.h>
#include <vector>
#include "Graph.h"
#include "DFS.h"
#include "BFS.h"
#include "ConnectedComponent.h"
#include "TopologicalSort.h"
#include "StrongConnectedComponent.h"
using namespace std;

void testGraph(){
	printf("Testing Graph API\n");

	Graph g(4);
	g.addUnweightedEdge(0,1);//unweighted directed edge
	g.addUnweightedEdge(0,2,true);//unweighted undirected edge
	g.addWeightedEdge(1,2,2.2);//weighted directed edge
	g.addWeightedEdge(1,3,2.5,true);//weighted undirected edge

	assert(g.hasEdge(0,1) == true);

	assert(g.hasEdge(0,2) && g.hasEdge(2,0));

	assert(g.hasEdge(0,3) == false);

	assert(g.getWeight(0,1) == 0);

	assert(g.getWeight(1,2) - 2.2 < 0.0001);

	Graph r ;
	Graph::reverse(g,r);

	assert(r.getNumberOfVertices() == g.getNumberOfVertices());
	assert(r.hasEdge(1 , 0) == true);
	assert(r.hasEdge(0 , 1) == false);
	assert(r.hasEdge(3 , 1) == true);
	assert(r.hasEdge(1 , 2) == false);

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

	assert(dfs.isConnectedTo(8) == true);

	assert((int)pathTo_0.size() == 0);

	assert((int)pathTo_4.size() == 2);

	assert((int)pathTo_5.size() == 3);

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

	assert(bfs.isConnectedTo(8) == true);

	assert(bfs.distanceTo(8) == 2);

	assert(bfs.distanceTo(5) == 3);

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

	assert(cc.sameComponent(3 , 4));
	assert(cc.sameComponent(5 , 4));
	assert(cc.sameComponent(5 , 6));

	assert(cc.sameComponent(7 , 8));
	assert(cc.sameComponent(7 , 9));

	assert(cc.sameComponent(7 , 0) == false);

	assert(cc.sameComponent(7 , 3) == false);

	assert(cc.sameComponent(1 , 6) == false);


	printf("passed!\n================\n");

}

void testTopologicalSort(){
	printf("Testing TopologicalSort\n");

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

	TopologicalSort tgs(g);

	assert((int)tgs.sorted().size() == 10);

	assert(tgs.precedes(2 , 7));
	assert(tgs.precedes(9 , 7));

	assert(tgs.precedes(3 , 4));
	assert(tgs.precedes(7 , 4));

	assert(tgs.precedes(0 , 1));
	assert(tgs.precedes(2 , 1));

	assert(!tgs.precedes(1 , 0));
	assert(!tgs.precedes(7 , 2));

	printf("passed!\n================\n");
}

void testStrongConnectedComponent(){
	printf("Testing StrongConnectedComponent\n");

	Graph g(13);
	g.addUnweightedEdge(0 , 1);
	g.addUnweightedEdge(0 , 5);
	g.addUnweightedEdge(2 , 0);
	g.addUnweightedEdge(3 , 2,true);
	g.addUnweightedEdge(3 , 5);
	g.addUnweightedEdge(5 , 4);
	g.addUnweightedEdge(4 , 2);
	g.addUnweightedEdge(6 , 0);
	g.addUnweightedEdge(6 , 4);
	g.addUnweightedEdge(11 , 4);
	g.addUnweightedEdge(6 , 8,true);
	g.addUnweightedEdge(7 , 6);
	g.addUnweightedEdge(7 , 9);
	g.addUnweightedEdge(6 , 9);
	g.addUnweightedEdge(9 , 10);
	g.addUnweightedEdge(10 , 12);
	g.addUnweightedEdge(12 , 9);
	g.addUnweightedEdge(9 , 11);
	g.addUnweightedEdge(11 , 12);

	StrongConnectedComponent scc(g);

	assert(scc.areStronglyConnected(0 , 3));
	assert(scc.areStronglyConnected(0 , 4));
	assert(scc.areStronglyConnected(6 , 8));
	assert(scc.areStronglyConnected(9 , 12));
	assert(scc.areStronglyConnected(0 , 1) == false);
	assert(scc.areStronglyConnected(0 , 7) == false);
	assert(scc.areStronglyConnected(8 , 11) == false);

	printf("passed!\n================\n");
}


int main(){
	testGraph();
	testDFS();
	testBFS();
	testConnectedComponent();
	testTopologicalSort();
	testStrongConnectedComponent();
	printf("All Passed!!!\n");
}