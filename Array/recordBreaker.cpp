// KickStart - 2020 Round D - Record Breaker
// Link - https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387171


#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll T, ans;
    cin>>T;
    for(ll t = 1; t<=T; t++){
        ll n, p;
        cin>>n;
        int a[n + 1];
        
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        
        a[n] = INT_MIN;
        int max_so_far = INT_MIN;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(a[i] > max_so_far && a[i]>a[i+1])
                cnt++;
                
            max_so_far = max(max_so_far, a[i]);
        }
        
        
        
        ans = cnt;
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}