// Prims algorithm to find minimum spanning tree
// link - https://www.spoj.com/problems/MST/


#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	vector<pair<int, int> > gr[n + 1];
	int vis[n+1];
    memset(vis, 0, sizeof vis);
	for(int i = 0; i<m; i++){
		int x, y, w;
		cin>>x>>y>>w;
		gr[x].push_back({y, w});
		gr[y].push_back({x, w});
	}
    
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
	long long int mst = 0;

	Q.push({0, 1}); // weight, start
	while(!Q.empty()){
		pair<int, int> best = Q.top(); // queue has front and priority queue has top
		Q.pop();

		int weight = best.first;
		int to = best.second;

        // cout<<"best "<<weight<<" "<<to<<endl;
		// if already visited, then the edge is not an active edge
		if(vis[to]) continue;

        // cout<<vis[to]<<endl;

		mst += weight;

		vis[to] = 1;


		for(auto x : gr[to]){ 
			if(!vis[x.first]){
				Q.push({x.second, x.first});
			}
		}
	}

	cout<<mst;

    
}