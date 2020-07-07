// CodeForces - Beautiful Graphs
// Link - https://codeforces.com/problemset/problem/1093/D
// Not able to Submit this - WA


#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
int cnt0, cnt1, can;

#define mod 998244353



int power(int a, int n){
	if(!n) return 1;
	int pt = power(a, n/2);
	pt*= pt; pt%=mod;
	if(n & 1){
		pt*=a;
		pt%=mod;
	}
	return pt;
}


void dfs(int i, vector<int> &vis, int parity = 0){
	if(vis[i]){
		if(1 + parity != vis[i]){
			can = 0;
		}
		return;
	}

	if(parity == 0){
		cnt0++;
		vis[i] = 1;
	}

	else{
		cnt1++;
		vis[i] = 2;
	}

	for(auto el:adj[i]){
		dfs(el, vis, 1 - parity);
	}

}



int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		adj.clear();
		adj.resize(n+1);
		while(m--){
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			
		}

		int ans = 1;
		vector<int> vis(n+1, 0);

		for(int i = 1; i<=n; i++){
			if(!vis[i]){
                //cout<<"Bla"<<i<<endl;
				cnt0 = 0, cnt1 = 0, can = 1;
				dfs(i, vis);
				if(!can)
					break;
				ans = (ans * (power(2, cnt0) + power(2,cnt1))) % mod; // important - ans * newAns , not ans + newAns
			}
		}
		
		if(!can){
            cout<<0<<endl;
        }
        else{
            cout<<ans<<endl;
        }

	}
}