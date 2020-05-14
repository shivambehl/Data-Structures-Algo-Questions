// n - number of locations to cover
// c[] - cost of petrol at each location
// l[] - need of petrol to to next location
// travelling i -> i+1 for i in [0, .. , n-1]


#include<bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll c[n], l[n];
        for(ll i = 0; i<n; i++){
            cin>>c[i];
        }
        for(ll i = 0; i<n; i++){
            cin>>l[i];
        }
        ll m = INT_MAX;
        ll cost = 0;
        for(ll i = 0; i<n; i++){
            if(c[i] < m) m = c[i];

            cost += l[i]*m;
        }
        cout<<cost<<endl;
    }
}
