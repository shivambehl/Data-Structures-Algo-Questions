// AGGRCOW - Aggressive cows - SPOJ
// Link - https://www.spoj.com/problems/AGGRCOW/
// assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible

#include<bits/stdc++.h>
using namespace std;
#define ll long long


bool placeCows(ll a[], ll n, ll c, ll m){
    ll count = 1;
    int prev = a[0];
    for(int i = 1; i<n; i++){
        if(a[i] - prev >= m){
            prev = a[i];
            count++;
            if(count == c)
                return true;
        }
    }
    return false;
}




int main(){
	ll t;
	cin>>t;

	while(t--){
		ll n, c;
		cin>>n>>c;
		ll num;
		ll a[n];
		for(ll i = 0; i<n; i++){
			cin>>a[i];
		}
		ll s = 0, e = a[n-1] - a[0] + 1;
		ll ans = 0;
		ll m;
        
        sort(a, a+n);

		while(s <= e){
			m = (s + e)/2;
			bool possible = placeCows(a, n, c, m);
            //cout<<m<<" - "<<possible<<endl;
			if(possible){
				ans = m;
				s = m+1;
			}
			else{
				e = m-1;
			}
		}
        //cout<<"bla\n";
		cout<<ans<<"\n";

	}
}