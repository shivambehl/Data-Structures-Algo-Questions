// Friends Pairing Problem
// Link - https://www.geeksforgeeks.org/friends-pairing-problem/

#include<bits/stdc++>
using namespace std;

int fun(int n){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
		
	return f(n-1) + (n-1)*f(n-2);
	
	/*
	
	for each I have 2 choices - 
	1. Remain single
	2. Pair up
	
	if nth person remain single - 
	f(n-1) cases will be there for rest
	
	and if (s)he pair up,
	n-1 kinds of pairs would be there
	and f(n-2) cases will be for each pair.
	
	*/
}



int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<fun(n)<<endl;
	}
}

