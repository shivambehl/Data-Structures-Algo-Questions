// SPOJ - MIXTURES
// Link - https://www.spoj.com/problems/MIXTURES/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int a[1005];
ll dp[1005][1005];

int sum(int i, int j){
    int sum = 0;
    while(i <= j){
        sum += a[i];
        sum %=100;
        i++;
    }
    return sum;
}


ll solve(int i, int j){
    if(i >= j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX;

    for(int k=i; k<=j; k++){
        dp[i][j] = min(dp[i][j], solve(i, k) + solve(k+1, j) + sum(i, k)*sum(k+1, j));
    }

    return dp[i][j];
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i =0; i<n; i++){
            cin>>a[i];
        }
        
        for(int i=0; i<=n; i++){
            for(int j = 0; j<=n; j++){
                dp[i][j] = -1;
            }
        }

        cout<<solve(0, n-1)<<endl;
    }
}