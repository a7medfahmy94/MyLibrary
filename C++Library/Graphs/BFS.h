#ifndef BFS_H
#define BFS_H

#include "Graph.h"
#include <string.h>
#include <queue>
using namespace std;

class BFS{

public:

BFS(Graph gr,int s):g(gr),source(s){
	int sz = g.getNumberOfVertices();
	visited = new bool[sz];
	distTo = new int[sz];

	memset(visited , 0 , sizeof(bool)*sz);
	memset(distTo , -1 , sizeof(int)*sz);
	bfs();
}

int distanceTo(int v){return distTo[v];}
int isConnectedTo(int v){return visited[v];}

private:

	void bfs(){
		queue< pair<int,int> > q;
		q.push(make_pair(source,0));
		visited[source] = true;
		distTo[source]  = 0;

		while(!q.empty()){
			int current = q.front().first;
			int d       = q.front().second;
			q.pop();
			vector<Edge> adj = g.getAdj(current);
			for(int i = 0 ; i < (int)adj.size(); i++){
				int other = adj[i].other(current);
				if(!visited[other]){
					visited[other] = true;
					distTo[other] = d+1;
					q.push(make_pair(other,d+1));
				}
			}

		}
	}

	Graph g;
	int source;
	bool* visited;
	int* distTo;


};


#endif