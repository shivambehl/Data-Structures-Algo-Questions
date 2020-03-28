// Codeforces Educational Round 84 A
// Sum of Odd Integers
// https://codeforces.com/contest/1327/problem/A

#include<iostream>
using namespace std;

#define ll long long

int main(){
	int t;
	ll n, k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(n%2 == k%2 && n >= k*k){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
