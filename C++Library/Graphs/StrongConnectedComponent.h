#ifndef STRONG_CONNECTED_COMPONENT_H
#define STRONG_CONNECTED_COMPONENT_H

#include "Graph.h"
#include "TopologicalSort.h"
#include <stdio.h>
using namespace std;

class StrongConnectedComponent{

public:
	StrongConnectedComponent(Graph gr):g(gr){
		int sz = g.getNumberOfVertices();
		strongComponents = new int[sz];
		memset(strongComponents,-1,sizeof(int)*sz);

		Graph reverseG ;
		Graph::reverse(g,reverseG);

		TopologicalSort topoSort(reverseG);
		vector<int> order = topoSort.sorted();

		for(int i = 0 ,f = 0; i < (int)order.size(); i++){
			if(strongComponents[order[i]] == -1)
				dfs(order[i] , f++);
		}

	}

	bool areStronglyConnected(int a,int b){
		return strongComponents[a]==strongComponents[b];
	}

	vector<int> strongComponentOf(int x){
		vector<int> ret;
		int sz = g.getNumberOfVertices();
		for(int i = 0 ; i < sz; i++){
			if(strongComponents[i] == strongComponents[x])
				ret.push_back(i);
		}
		return ret;
	}

private:

	void dfs(int x,int flag){
		strongComponents[x] = flag;
		vector<Edge> adj = g.getAdj(x);
		int size = (int)adj.size();
		for(int i = 0 ; i < size; i++){
			int other = adj[i].other(x);
			if(strongComponents[other] == -1){
				dfs(other,flag);
			}
		}
	}

	Graph g;
	int* strongComponents;

};

#endif