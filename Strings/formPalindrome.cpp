// Form a palindrome - GeeksforGeeks
// Link - https://practice.geeksforgeeks.org/problems/form-a-palindrome/0
// Dynamic Programming

#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int fun(int s, int e, string a){
	if(s >= e)
		return 0;
	if(dp[s][e] != -1)
		return dp[s][e];
	if(a[s] == a[e])
		return dp[s][e] = fun(s+1, e-1, a);
	return dp[s][e] = min(fun(s+1, e, a), fun(s, e-1, a)) + 1;
}


int main(){
	int t; cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n = s.length();
		memset(dp, -1, sizeof dp);
		cout<<fun(0, n-1, s)<<"\n";
	}
	return 0;
}
