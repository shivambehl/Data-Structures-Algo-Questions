// Longest Palindromic Substring - GeeksforGeeks
// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
// This is O(n2) space complexity solution
// O(1) time soltion can be found at - 
// https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/?ref=rp

#include<bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n = s.size();
		
		bool dp[n][n];
		memset(dp, true, sizeof(dp));
		
		int r, c;
		int rn = 0, cn = 0;
		int flag;
		for(int i = 0; i<n; i++){
			flag = 0;
			r = 0; c = i;
			while(c < n){
				if(r == c) dp[r][c] = true;
				else{
					if(s[r] == s[c] && dp[r+1][c-1] == true){
						dp[r][c] = true;
						if(flag == 0 ){
							flag = 1;
							rn = r;
							cn = c;
						}
					}
					else
						dp[r][c] = false;
				}
				r++; c++;
			}
		}
		
		// for(int i = 0; i<n; i++){
		// 	for(int j = 0; j<n; j++){
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		
		for(int i = rn; i<=cn; i++){
			cout<<s[i];
		}
		cout<<endl;
	}
	
	return 0;
}
