// Largest permutation after at most k swaps - GeeksforGeeks, Hackerrank
// Link - https://www.hackerrank.com/challenges/largest-permutation/problem (Hackerrank)
// Gfg - https://practice.geeksforgeeks.org/problems/largest-permutation/0 (Not Solved)

#include<bits/stdc++.h>
using namespace std;

void fun(int n, int k, int a[]){
	int pos[n+1];
	for(int i = 0; i<n; i++){
		pos[a[i]] = i;
	}
	for(int i = 0; i<n && k; i++){
		if(a[i] == n-i)
			continue;
		
		int t = pos[n-i]; 
        pos[a[i]] = pos[n-i]; 
        pos[n-i] = i;
		swap(a[i], a[t]);
		k--;
	}
}


int main(){
	int n;
	cin>>n;
	int k;
	cin>>k;
	int a[n];
	
	for(int i =0; i<n; i++){
		cin>>a[i];
	}
	
	fun(n, k, a);
	
	
	for(int i = 0; i<n; i++)
		cout<<a[i]<<" ";
	return 0;
	
}
