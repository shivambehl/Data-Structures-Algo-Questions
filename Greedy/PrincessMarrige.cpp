// Codeforces Educational Round 84 B
// Princesses and Princes
// https://codeforces.com/contest/1327/problem/B


#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<bool> done(n+1, 0);
		
		int free_princess = 0;
		
		for(int i = 1; i<=n; i++){
			int k; cin>>k;
			int princess_done = 0;
			while(k--){
				int p; cin>>p;
				
				if(princess_done == 1)
					continue;
				
				if(done[p] == 1)
					continue;
				
				done[p] = 1;
				princess_done = 1;
				
			}
			
			if(princess_done == 0)
				free_princess = i;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
		}
		if(free_princess == 0){
			cout<<"OPTIMAL\n";
			continue;
		}
		int free_prince = 0;
		for(int i = 1; i<=n; i++){
			if(done[i] == 0){
				free_prince = i;
				break;
			}
		}
		cout<<"IMPROVE\n";
		cout<<free_princess<<" "<<free_prince<<"\n";
	}
}
