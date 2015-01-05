#include <iostream>
#include "Graph.h"

using namespace std;

int main(){
	Graph g(4);
	g.addUnweightedEdge(0,1);//unweighted directed edge
	g.addUnweightedEdge(0,2,true);//unweighted undirected edge
	g.addWeightedEdge(1,2,2.2);//weighted directed edge
	g.addWeightedEdge(1,3,2.5,true);//weighted undirected edge

	cout << g.hasEdge(0 , 1) << "\n";//1
	cout << g.hasEdge(0 , 3) << "\n";//0

	cout << g.getWeight(0 , 1) << "\n";//0
	cout << g.getWeight(1 , 2) << "\n";//2.2

	vector< vector<Edge> > adj = g.getAdj();

	for(int i = 0 ; i < (int)adj.size(); i++){
		cout << "Vertex (" << i << ") Edges to : " << "\n";
		for(int j = 0 ; j < (int)adj[i].size(); j++){
			cout << adj[i][j].other(i) << " ";
		}
		cout << "\n";
	}

}