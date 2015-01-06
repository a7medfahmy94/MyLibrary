#ifndef CONNECTED_COMPONENT_H
#define CONNECTED_COMPONENT_H

//works only with undirected graphs
#include "Graph.h"
#include <string.h>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;

class ConnectedComponent
{
public:
	ConnectedComponent(Graph gr):g(gr){
		int sz = g.getNumberOfVertices();
		cc = new int[sz];
		memset(cc , -1 , sizeof(int)*sz);

		for(int i = 0,f=0; i < sz; i++){
			if(cc[i] == -1)
				bfs(i , f++);
		}

	}

	int component(int s){return cc[s];}
	bool sameComponent(int a,int b){return cc[a]==cc[b];}

private:
	void bfs(int source,int flag){
		queue< int > q;
		q.push(source);
		cc[source] = flag;

		while(!q.empty()){
			int current = q.front();
			q.pop();
			vector<Edge> adj = g.getAdj(current);
			for(int i = 0 ; i < (int)adj.size(); i++){
				int other = adj[i].other(current);
				if(cc[other] == -1){
					cc[other] = flag;
					q.push(other);
				}
			}

		}
	}

	Graph g;
	int* cc;
};

#endif