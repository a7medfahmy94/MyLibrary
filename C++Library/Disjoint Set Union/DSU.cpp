#include <bits/stdc++.h>
using namespace std;

struct item{
	int val; //this can be replaced with ant kind of data
	int par;
};

int parent[10]; //parent[i] is the negative value of the number of items
								//associated with that parent

item items[10]; //those are the items


int root(int v){
	//if we reached a negative value, we return the index
	//if not, we "flat" the tree for efficiency
	return parent[v] < 0 ? v : (parent[v] = root(parent[v]));
}

void merge(int a,int b){
	int x = root(a) , y = root(b);
	if(y < x){swap(x,y);} //always merge the smallest into the largest
	parent[x] += parent[y];
	parent[y] = x;
}

int main(){
	for(int i=0;i<10;i++){
		parent[i] = -1;
		items[i].par = i;
		items[i].val = i*2;
	}

	merge(2 , 3);
	merge(3 , 4);
	cout << root(items[4].par) << endl;
	cout << root(items[3].par);

}