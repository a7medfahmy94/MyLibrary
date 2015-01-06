#ifndef DFS_H
#define DFS_H

#include "Graph.h"
#include <vector>
#include <stack>
#include <string.h>
using namespace std;

class DFS{

public:
	DFS(Graph gr,int s):g(gr),source(s){
		int sz = g.getNumberOfVertices();
		visited = new bool[sz];
		edgeTo  = new int[sz];
		memset(visited , 0 , sizeof(bool)*sz);
		memset(edgeTo , -1 , sizeof(int)*sz);
		dfs(source);
	}


	vector<int> pathTo(int x){
		if(edgeTo[x] == -1){return vector<int>();}
		stack<int> s;
		while(x != source){
			s.push(x);
			x = edgeTo[x];
		}
		vector<int> ret;
		while(!s.empty()){
			ret.push_back(s.top());
			s.pop();
		}
		return ret;
	}

	bool isConnectedTo(int x){return visited[x];}

private:

	void dfs(int x){
		visited[x] = true;
		vector<Edge> adj = g.getAdj(x);
		int size = (int)adj.size();
		for(int i = 0 ; i < size; i++){
			int other = adj[i].other(x);
			if(!visited[other]){
				edgeTo[other] = x;
				dfs(other);
			}
		}
	}

	Graph g;
	int source;
	bool* visited;
	int* edgeTo;
};


#endif