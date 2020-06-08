#include<bits/stdc++.h>
using namespace std;


int dfs(list<pair<int, int> > l, int n, int u, int &ans, bool visited[]){
	visited[u] = true;

	int count = 0;
	int total = 0;

	for(auto nbr:l[u]){
		v = nbr.first;
		cost = nbr.second;

		if(!visited[v]){
			count = dfs(l, n, v, ans, visited);
			total += count;
		}

		ans += min(count, n-count)*cost;
	}

	return total + 1;

}



int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		list<pair<int, int> > l;
		
		for(int i = 0; i<n; i++){
			int u, v, cost;
			cin>>u>>v>>cost;
			l[u].push_back(make_pair(v, cost));
			l[v].push_back(make_pair(u, cost));
		}

		bool visited[n+1];
		memset(visited, false, sizeof visited);
		int ans = 0;
		int u = 0;
		dfs(l, n, u, ans, visited);

		cout<<ans<<endl;
	}

	return 0;
}