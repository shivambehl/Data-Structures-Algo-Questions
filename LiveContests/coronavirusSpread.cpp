
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n], vis[n];
		memset(vis, 0, sizeof(vis));
		int mx=INT_MIN, mn=INT_MAX;
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		for(int i = 0; i<n; i++){
			
			int clusCount = 0;
			if(!vis[i]){
				
				stack<int> s;
				s.push(i);
				vis[i] = 1;
				while(!s.empty()){
					int u = s.top();
					s.pop();
					clusCount++;
					
//					if(abs(a[u] - a[u-1]) <= 2
//					 && !vis[u-1]){
//						s.push(u-1);
//						vis[u-1] = 1;
//					}
					
					if(abs(a[u+1] - a[u]) <= 2
					&& !vis[u+1]){
						s.push(u+1);
						vis[u+1] = 1;
					}
				}
				
				mn = min(mn, clusCount);
				mx = max(mx, clusCount);
				
			}
		}
		cout<<mn<<" "<<mx<<endl;
	}
}
