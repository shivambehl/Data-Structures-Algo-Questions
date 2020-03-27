// BALIFE - Load Balancing - SPOJ
// https://www.spoj.com/problems/BALIFE/

#include<bits/stdc++.h>
using namespace std;

int main(){
	while(1){
		int n; cin>>n;
		if(n == -1){
			break;
		}
		
		int a[n], load = 0;
		for(int i = 0; i<n; i++){
			cin>>a[i];
			load += a[i];
		}
		if(load%n != 0){
			cout<<"-1"<<endl;
			continue;
		}
		load = load/n;
		
		int diff = 0;
		int max_load = INT_MIN;
		for(int i = 0; i<n; i++){
			diff += (a[i] - load);
			int ans = max(diff, -diff); // to take magnitude 
			max_load = max(ans, max_load);
		}
		
		cout<<max_load<<endl;
		
	}
}
