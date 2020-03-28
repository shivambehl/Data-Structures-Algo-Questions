// Google Kickstart - Round A 2020
// Question 2 - Plates

#include<bits/stdc++.h>
using namespace std;

int dp[51][51*31];
int pref[51][31];
int n, k, p;


int plates(int idx, int taken){
	if(taken == p)
		return 0;
	if(taken > p || idx > n)
		return INT_MIN;
	if(dp[idx][taken] != -1)
		return dp[idx][taken];
	int ans = INT_MIN;
	for(int i = 0; i<=k; i++)
		ans = max(ans, pref[idx][i] + plates(idx + 1, taken + i));
	dp[idx][taken] = ans;
	return ans;
}


int main(){
	int t;
	cin>>t;
	for(int a = 1; a<=t; a++){
		cin>>n>>k>>p;
		memset(dp, -1, sizeof(dp));
		memset(pref, 0, sizeof(pref));
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=k; j++){
				int val;
				cin>>val;
				pref[i][j] = pref[i][j-1] + val;
			}
		}

		cout<<"Case #"<<a<<": "<<plates(1, 0)<<endl;
		
	}
}
