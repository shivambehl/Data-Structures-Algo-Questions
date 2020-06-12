// implementing bellman ford algorithm


#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int n, int src, vector<vector<int> > edges){
	vector<int> dis(n + 1, INT_MAX);
	dis[src] = 0;
	// relax all the edges n-1 times
	for(int i = 0; i<n-1; i++){
		for(auto x : edges){
			int from, to, weight;
			from = x[0]; to = x[1]; weight = x[2];
			if(dis[from]!= INT_MAX && dis[to] > dis[from] + weight){
				// relaxation
				dis[to] = dis[from] + weight;
			}
		}
	}
	// negative weight cycle
	for(auto x:edges){
		int from, to, weight;
		from = x[0]; to = x[1]; weight = x[2];
		if(dis[from]!= INT_MAX && dis[to] > dis[from] + weight){
			cout<<"negative weight cycle";
			exit(0); // exits from code
		}
	}
	return dis;
}


int main(){
	int n, m;
	cin>>n>>m;
	vector<vector<int> > edges;
	for(int i = 0; i<n; i++){
		int from, to, weight;
		cin>>from>>to>>weight;
		edges.push_back({from, to, weight});
	}
	int src = 1;
	vector<int> dis = bellman_ford(n, src, edges);
    for(int i = 1; i<=n; i++){
        cout<<dis[i]<<" ";
    }

}
