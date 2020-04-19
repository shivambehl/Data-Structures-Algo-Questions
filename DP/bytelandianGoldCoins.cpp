// Bytelandian gold coins - CodeChef
// Link - https://www.codechef.com/problems/COINS
// Problem Code: COINS

#include<bits/stdc++.h>
using namespace std;

#define ll long long

unordered_map<ll, ll> dp;

ll fun(ll n){
	if( n < 10)
		return n;
	
	if(dp.find(n) != dp.end())
		return dp[n];
	
	ll a = fun(n/2);
	ll b = fun(n/3);
	ll c = fun(n/4);
	
	return dp[n] = max(n, a + b + c);
}


int main(){
	ll n; cin>>n;
	cout<<fun(n);

    return 0;
}
