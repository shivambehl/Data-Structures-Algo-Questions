// KickStart- 2020 Round D - Alien Piano
// Link - https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000387174


// Self Note - Read Editorial


#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll T, ans;
    cin>>T;
    for(ll t = 1; t<=T; t++){
        ll n, p;
        ans = 0;
        cin>>n;
        ll a[n], change[n];

        for(int i = 0; i<n; i++){
            cin>>a[i];
        }

        change[0] = 0;

        // Set Values
        for(int i = 1; i<n; i++){
            if(a[i] < a[i-1])
                change[i] = -1;
            else if(a[i] > a[i-1])
                change[i] = 1;
            else
                change[i] = 0;
        }

        // analyse sum
        int sum[n]; sum[0] = 0;
        int inc =0, dec = 0;
        for(int i = 1; i<n; i++){
            sum[i] = sum[i-1] + change[i];
            if(sum[i] > sum[i-1]){
                inc++;
                dec = 0;
            }
            else if(sum[i] < sum[i-1]){
                dec++;
                inc = 0;
            }
            if(inc > 0 || dec > 0 ){
                if(inc%4 == 0 && dec%4 == 0){
                    inc = 0;
                    dec = 0;
                    ans++;
                }
            }
            
        }
        
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}