#include<bits/stdc++.h>
using namespace std;


int fun(int s, int e, int a[]){
	if(s == e)
		return a[s];
	int m = (s + e)/2;
	int left = 0, right = 0;
	left = fun(s, m, a);
	right = fun(m+1, e, a);
	
	int maxl = INT_MIN;
	int sum = 0;
	for(int i=m; i>=s; i--){
		sum +=a[i];
		maxl = max(maxl, sum);
	}
	sum = 0;
	int maxr = INT_MIN;
	for(int i=m+1; i<=e; i++){
		sum += a[i];
		maxr = max(maxr, sum);
	}
	int ans = max(max(left, right), maxl + maxr);
	//cout<<s<<" "<<e<<" - "<<ans<<" "<<maxl<<" "<<maxr<<endl;
	return ans;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n];
		for(int i = 0; i<n; i++){
			cin>>a[i];
		}
		cout<<fun(0, n-1, a)<<endl;
	}
}
