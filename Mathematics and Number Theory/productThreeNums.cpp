// Codeforces - Product of Three Numbers
// Link - https://codeforces.com/problemset/problem/1294/C


#include <iostream>
#include<set>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        set<int> factors;
        int i;
        for(i = 2; i*i < n; i++){
            if(n%i == 0){
                factors.insert(i);
                n /= i;
                break;
            }
        }
        i++;
        for(; i*i < n; i++){
            if(n%i == 0 && !factors.count(i)){
                factors.insert(i);
                n /= i;
                break;
            }
        }

        if(factors.count(n) || factors.size() < 2 || n==1){
            cout<<"No\n";
        }
        else{
            factors.insert(n);
            cout<<"Yes"<<endl;
            for(auto u:factors) cout<<u<<" ";
            cout<<"\n";
        }
    }
}
