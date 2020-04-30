// Maximum of all subarrays of size k - Geeksforgeeks
// Link - https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

// Uses an interesting data structure - Deque,
// though it is basically a doubly ended linkedlist


#include<bits/stdc++.h>
using namespace std;

void showList(list<int> l){
	for(auto a:l){
		cout<<a<<" ";
	}
	cout<<endl;
}


void findMaxSlideWindow(int n, int k, int a[]){
	
	list<int> l;
	int i = 0;

	for(i = 0; i<k; ++i){
		while(!l.empty() && a[l.back()] <= a[i])
			l.pop_back();
			
		l.push_back(i);
	}
	
	//showList(l);
	
	
	for(; i<n; i++){
		
		cout<<a[l.front()]<<" ";
		
		while(!l.empty() && l.front() < i - k + 1)
			l.pop_front();
		
		while(!l.empty() && a[l.back()] <= a[i])
			l.pop_back();
			
		l.push_back(i);
		
		
	}
	cout<<a[l.front()]<<endl;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n];
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		findMaxSlideWindow(n, k, a);
	}
	return 0;
}
