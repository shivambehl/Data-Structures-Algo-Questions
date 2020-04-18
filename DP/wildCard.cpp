// Wildcard pattern Matching
// Link - https://www.geeksforgeeks.org/wildcard-pattern-matching/


#include<bits/stdc++.h>
using namespace std;

int main(){
    char in[1005], out[1005];
    cin>>out>>in;

    bool dp[1005][1005];

    int n, m;
    n = strlen(in);
    m = strlen(out);

    dp[0][0] = 1;

    for(int i=1; i<=n; i++){
        if(in[i-1] == '*')dp[i][0] = dp[i-1][0];
        else dp[i][0] = 0;
    }
    
    for(int i=1; i<=m; i++)
        dp[0][i] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(in[i-1] == '?' || in[i-1] == out[j-1]) dp[i][j] = dp[i-1][j-1];
            if(in[i-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
        }
    }

    if(dp[n][m] == 1) cout<<"MATCHED";
    else cout<<"NOT MATCHED";
}
