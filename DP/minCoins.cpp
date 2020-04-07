#include <bits/stdc++.h>
using namespace std;

int dp[100005];

int minCoins(int coins[], int val, int n){
    int mn = INT_MAX;
    if(dp[val] != -1)
        return dp[val];
    for(int i = 0; i<n; i++){
        mn = min(minCoins(coins, val - coins[i], n), mn);
    }
    dp[val] = mn;
    return mn;
}



int main() {
    int val, n;
    cin>>val>>n;
    int a[n];
    memset(a, -1, sizeof(a));
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cout<<minCoins(a, val, n);
}

