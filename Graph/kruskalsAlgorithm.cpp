// algorithm to find Minimum spanning tree

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
	int n, m;
	cin>>n>>m;
	vector<vector<int> > edges(m);
	for(int i = 0; i<m; i++){
		int x, y, w;
		cin>>x>>y>>w;
		x--; y--;
		edges[i] = { w, x, y};
	}

	sort(edges.begin(), edges.end());
	// works without comparator because vector is compared using first vector
	int ans = 0;
	dsu G;
	G.init(G);
	for(i = 0; i<m; i++){
		int x = edges[i][1];
		int y = edges[i][2];
		int z = edges[i][0];

		if(G.get(x) != G.get(y)){
			G.unite(x, y);
			ans += w;
		}
	}
}