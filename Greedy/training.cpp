// Google Kickstart 2019 ROUND A - Q1
// Link - https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e01/00000000000698d6

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll T;
    cin>>T;
    for(ll t = 1; t<=T; t++){
        ll n, p;
        cin>>n>>p;
        ll a[n];
        for(ll i = 0; i<n; i++){
            cin>>a[i];
        }
        sort(a, a + n);
        ll sum[n+1];
        sum[0] = 0;
        for(ll i = 1; i<=n; i++){
            sum[i] = sum[i-1] + a[i-1];
        }
        ll mn = INT_MAX;
        for(ll j = p; j<=n; j++){
            mn = min(mn, a[j-1]*p - (sum[j] - sum[j-p]));
        }
        
        ll ans = mn;
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}