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
	for(i = 0; i<k; i++){
		while(!l.empty() && a[l.back()] <= a[i])
			l.pop_back();
			
		l.push_back(i);
	}
	
	
	
	
	for(; i<n; i++){
		
		cout<<l.front()<<" ";
		
		while(!l.empty() && l.front() < i - k + 1)
			l.pop_front();
		
		while(!l.empty() && a[l.back()] <= a[i])
			l.pop_back();
			
		l.push_back(i);
		
		
	}
	cout<<l.front()<<endl;
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
