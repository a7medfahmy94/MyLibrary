#include <vector>
#include "Edge.h"
#define sz(x) (int)(x.size())

using namespace std;


class Graph{
public:
	Graph(int v){
		adj.resize(v);
	}

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

	std::vector< vector<Edge> > getAdj(){return adj;}

private:
	std::vector< vector<Edge> > adj;
};

