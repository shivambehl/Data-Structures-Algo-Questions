// Longest Common Prefix in an Array - geeksforgeeks
// link - https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0


#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s[n];
	    for(int i = 0; i<n; i++){
	        cin>>s[i];
	    }
	    if(n == 1){
	        cout<<s[0]<<endl;
	        continue;
	    }
	    sort(s, s + n);
	    string a, b;
	    a = s[0];
	    b = s[n-1];
	    
	    //cout<<a<<" "<<b<<endl;
	    int m = min(a.length(), b.length());
	    int ans = 0;
	    int flag = 0;
	    while(a[ans] == b[ans] && m>0){
	        flag = 1;
	        cout<<a[ans];
	        ans++;
	        m--;
	    }
	    if(flag == 0)
	        cout<<-1;
	    cout<<endl;
	}
	return 0;
}
