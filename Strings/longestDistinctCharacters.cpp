// Longest Distinct characters in string - GeeksforGeeks
// Link - https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0/
// Variation of Kadane's Algorithm

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int mx = INT_MIN;
	    int n = s.length();
	    int i=0, j=0;
	    int a[256];
	    memset(a, 0, sizeof a);
	    for(i = 0; i<n; i++){
	        while(a[s[i]] != 0){
	            a[s[j]]--;
	            j++;
	        }
	        a[s[i]]++;
	        mx = max(mx, i - j + 1);
	    }
	    cout<<mx<<endl;
	}
	return 0;
}
