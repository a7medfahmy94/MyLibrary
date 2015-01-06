#ifndef TOPOLOGICAL_SORT
#define TOPOLOGICAL_SORT

/*
Assumptions:
Directed Acyclic Connected Graph
*/

#include "Graph.h"
#include <vector>
#include <algorithm>
using namespace std;

class TopologicalSort
{
public:
	TopologicalSort(Graph gr):g(gr){
		int sz = g.getNumberOfVertices();
		visited = new bool[sz];
		memset(visited , 0 , sizeof(bool)*sz);

		for(int i = 0 ; i < sz; i++){
			if(!visited[i]){
				bfs(i);
			}
		}
		reverse(sort.begin(),sort.end());
	}

	vector<int> sorted(){return sort;}
	bool precedes(int a,int b){
		int id1 = -1 , id2 = -1;
		for(int i = 0 ; i < (int)sort.size(); i++){
			if(id1 > -1 && id2 > -1)break;
			if(sort[i] == a)id1 = i;
			if(sort[i] == b)id2 = i;
		}
		return id1 < id2;
	}

private:
	void bfs(int source){
		visited[source] = true;
		vector<Edge> adj = g.getAdj(source);
		for(int i = 0 ; i < (int)adj.size(); i++){
			int other = adj[i].other(source);
			if(!visited[other]){
				bfs(other);
			}
		}
		sort.push_back(source);
	}

	bool* visited;
	Graph g;
	vector<int> sort;
};

#endif