// BAISED - Biased Standings - SPOJ
// https://www.spoj.com/problems/BAISED/

// count sort implementation

#include<iostream>
#include<cmath>
using namespace std;

#define ll long long

int main(){
	ll t;
	cin>>t;
	
	while(t--){
		ll n;
		cin>>n;
		ll a[n+5] = {0};
		string name;
		ll rank;
		
		for(ll i = 0; i<n; i++){
			cin>>name>>rank;
			a[rank]++;
		}
		ll nextRank = 1;
		ll sum = 0;
		for(ll i = 1; i<=n; i++){
			while(a[i] != 0){
			    a[i]--;
				sum += abs(nextRank - i);
				nextRank++;
			}
		}
		cout<<sum<<endl;
	}
}
