#include<bits/stdc++.h>
using namespace std;


int dfs(list<pair<int, int> > l[], int n, int u, int &ans, bool visited[]){

	visited[u] = true;

	int count = 0;
	int total = 0;
	for(auto nbr:l[u]){
		int v = nbr.first;
		int cost = nbr.second;
        //cout<<v<<" "<<cost<<endl;
		if(!visited[v]){
			count = dfs(l, n, v, ans, visited);
            //cout<<count<<endl;
            //cout<<"bla"<<endl;
            ans += 2*min(count, n-count)*cost;
			total += count;
		}

	}

	return total + 1;
}



int main(){
	int t;
	cin>>t;
	int T = 1;
	while(t--){
		int n;
		cin>>n;
		list<pair<int, int> > l[n+1];
		
		for(int i = 0; i<n-1; i++){
			int u, v, cost;
			cin>>u>>v>>cost;
			l[u].push_back(make_pair(v, cost));
			l[v].push_back(make_pair(u, cost));
		}

		bool visited[n+1];
		memset(visited, false, sizeof visited);
		int ans = 0;
		int u = 1;
		dfs(l, n, u, ans, visited);

		cout<<"Case #"<<T<<": "<<ans<<endl;
	}

	return 0;
}