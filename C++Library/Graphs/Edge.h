#ifndef EDGE_H
#define EDGE_H

class Edge{
public:
	Edge(int a,int b,float f):v(a),w(b),weight(f){}

	int either(){return v;}
	int other(int a){return a==v?w:v;}
	float getWeight(){return weight;}

	bool operator==(Edge e){
		return e.v==this->v && e.w==this->w && e.weight==this->weight;
	}
private:
	int v,w;
	float weight;
};

#endif