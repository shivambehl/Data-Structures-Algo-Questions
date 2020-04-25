#include<bits/stdc++.h>
using namespace std;


int main(){
	int t; cin>>t;
	getchar();
	while(t--){
		string s;
		getline(cin, s);
		
		int a[256];
		memset(a, 0, sizeof a);
		
		int i = 0, r = 0;
		for(i =0; i<s.length(); i++){
			if(a[s[i]] == 0){
				a[s[i]] = 1;
				s[r] = s[i];
				r++;
			}
		}
		i = 0;
		s[r] = '\0';
		while(s[i]){
			cout<<s[i];
			i++;
		}
		cout<<endl;
	}
}
