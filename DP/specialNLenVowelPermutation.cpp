#include <bits/stdc++.h>
using namespace std;


long findVowelPermutation(int n, vector<vector<int> graph>){
    long dp[n + 1][5];

    for(int i = 0; i<5; i++){
        dp[1][i] = 1;
    }


    for(int i = 1; i<n; i++){
        for(int u = 0; u<5; u++){
            dp[i+1][u] = 0;
            for(auto v: graph[u]){
                dp[i+1][u] += dp[i][v];
            }
        }
    }

    long ans = 0;
    for(int i = 0; i<5; i++){
        ans += dp[n][i];
    }

    return ans;
}