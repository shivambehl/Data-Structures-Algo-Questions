// Google Kickstart 2020 - Round A
// Workout
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f5b


#include<bits/stdc++.h>
using namespace std;

int n, k, a[100005];

bool check(int c){
	int sum = 0;
	for(int i = 0; i <n-1; i++){
		sum += (a[i+1] - a[i] - 1)/c;
	}
	if(sum <= k) return true;
	else return false;
}


int binarySearch(int l, int h){
	while(l < h){
		int m = (l + h)/2;
		//cout<<m<<" ";
		if(check(m)){
			h = m;
		}
		else{
			l = m+1;
		}
	}
	return l; // here, low and high are equal
}


int main(){
	int t; cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		cout<<binarySearch(1, 1e9);
	}
}
