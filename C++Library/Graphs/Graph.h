#ifndef GRAPH_H
#define GRAPH_H


#include <vector>
#include "Edge.h"
#define sz(x) (int)(x.size())

using namespace std;


class Graph{
public:
	Graph(){vertices=0;}
	Graph(int v){
		adj.resize(v);
		vertices = v;
	}

	void setNumberOfVertices(int v){vertices = v;adj.resize(v);}

	void addUnweightedEdge(int a,int b,bool undirected=false){
		if(a < sz(adj) && b < sz(adj)){
			adj[a].push_back(Edge(a,b,0));
			if(undirected){adj[b].push_back(Edge(b,a,0));}
		}
	}

	void addWeightedEdge(int a,int b,float f,bool undirected=false){
		if(a < sz(adj) && b < sz(adj)){
			adj[a].push_back(Edge(a,b,f));
			if(undirected){adj[b].push_back(Edge(b,a,f));}
		}
	}



	float getWeight(int a,int b){
		for(int i =0  ; i < sz(adj[a]);i++){
			if(adj[a][i].other(a) == b)return adj[a][i].getWeight();
		}
		return -1.0;
	}


	bool hasEdge(int a,int b){
		for (int i = 0; i < sz(adj[a]); ++i){
			if(adj[a][i].other(a) == b)return true;
		}
		return false;
	}

	vector< vector<Edge> > getAdj(){return adj;}
	vector<Edge> getAdj(int x){return adj[x];}

	int getNumberOfVertices(){return vertices;}

	static void reverse(Graph& source,Graph& destination){
		vector< vector<Edge> > newAdj(source.vertices);

		for(int i = 0 ; i < source.vertices; i++){
			int sz = source.adj[i].size();
			for(int j = 0 ; j < sz; j++){
				int other = source.adj[i][j].other(i);
				newAdj[other].push_back(source.adj[i][j]);
			}
		}
		destination.vertices = source.vertices;
		destination.adj = newAdj;
	}

private:
	vector< vector<Edge> > adj;
	int vertices;
};

#endif