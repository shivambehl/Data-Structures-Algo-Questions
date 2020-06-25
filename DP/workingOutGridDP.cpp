// Working Out
// Link - https://codeforces.com/contest/429/problem/B
// Really Beautiful Problem with grid based DP, Do look at the editorial


#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll grid[1002][1002];
ll boy_start[1002][1002], boy_end[1002][1002], girl_start[1002][1002], girl_end[1002][1002];


ll findMaximumCaloriesBurnt(ll n, ll m){
	

	for(ll i = 1; i<=n; i++){
		for(ll j = 1; j<=m; j++){
			boy_start[i][j] = grid[i][j] + max(boy_start[i-1][j], boy_start[i][j-1]);
		}
	}


	for(ll i = n; i>=1; i--){
		for(ll j = m; j>=1; j--){
			boy_end[i][j] = grid[i][j] + max(boy_end[i+1][j], boy_end[i][j+1]);
		}
	}


	for(ll i = 1; i<=n; i++){
		for(ll j = m; j>=1; j--){
			girl_end[i][j] = grid[i][j] + max(girl_end[i-1][j], girl_end[i][j+1]);
		}
	}


	for(ll i = n; i>=1; i--){
		for(ll j = 1; j<=m; j++){
			girl_start[i][j] = grid[i][j] + max(girl_start[i+1][j], girl_start[i][j-1]);
		}
	}

/*
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=m; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=m; j++){
            cout<<boy_start[i][j]<<" ";
        }
        cout<<endl;
    }
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=m; j++){
            cout<<boy_end[i][j]<<" ";
        }
        cout<<endl;
    }
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=m; j++){
            cout<<girl_start[i][j]<<" ";
        }
        cout<<endl;
    }
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=m; j++){
            cout<<girl_end[i][j]<<" ";
        }
        cout<<endl;
    }
*/

	ll ans = 0;
	for(ll i = 2; i<n; i++){
		for(ll j = 2; j<m; j++){
			ll type1 = boy_start[i-1][j] + boy_end[i+1][j] + girl_start[i][j-1] + girl_end[i][j+1];
			ll type2 = boy_start[i][j-1] + boy_end[i][j+1] + girl_start[i+1][j] + girl_end[i-1][j];
			ans = max(ans, max(type1,type2));
		}
	}

	return ans;

}


int main(){
	ll n, m;
	cin>>n>>m;


	memset(boy_start, 0, sizeof boy_start);
	memset(boy_end, 0, sizeof boy_end);
	memset(girl_start, 0, sizeof girl_start);
	memset(girl_end, 0, sizeof girl_end);
	
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=m; j++){
            cin>>grid[i][j];
        }
    }
	cout<<findMaximumCaloriesBurnt(n, m);
}