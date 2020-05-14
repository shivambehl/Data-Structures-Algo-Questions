// Google KickStart - 2020 - Round B - Bus Routes
// Link - https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d83bf


#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t = 0; t<T; t++){
        int n;
        long long int d;
        cin>>n;
        cin>>d;
        long long int a[n];
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        long long int ans = d;
        for(int i = n-1; i>=0; i--){
            ans = ans - ans%a[i];
        }
        cout<<"Case #"<<t+1<<": "<<ans<<endl;
    }
}
