// disjoint set data structure with path compression

#include<bits/stdc++.h>
using namespace tsd;

struct dsu {
	vector<int> p;

	void init(int n){
		p.clear();
		p.resize(n);
		for(int i = 0; i<n; i++){
			p[i] = i;
		}
	}

	int get(int x){
		return (x == p[x] ? x : (p[x] = get(p[x])) );
	}

	void unite(int x, int y){
		x = get(x);
		y = get(y);
		if(x != y){
			p[x] = y;
		}
	}
};


int main(){

}