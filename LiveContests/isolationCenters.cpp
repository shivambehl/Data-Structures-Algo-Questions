#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		string s;
		cin>>s;
		int a[26];
		memset(a, 0, sizeof a);
		for(int i = 0; i<n; i++){
			a[s[i] - 'a']++;
		}
		
		for(int i = 0; i<q; i++){
			int C;
			cin>>C;
			int ans = 0;
			for(int i = 0; i<n; i++){
				if(C < a[i])
					ans += a[i] - C;
			}
			cout<<ans<<endl;
		}
	}
}
