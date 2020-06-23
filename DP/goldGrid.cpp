// This is a GridDP problem
// More accuratly, it is prefix sum in 2 dimesnions
// We have to devide a grid of 0's and 1's in 4 parts such that the part with even the minimum of sum is maximised
// it is called goldGrid and maybe present on HackerBlocks


#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int grid[n+1][n+1];
	memset(grid, 0, sizeof grid);
	for(int i=0; i<m; i++){
		int a, b;
        cin>>a>>b;
		grid[a-1][b-1] = 1;
	}

	int dp[n+1][n+1];
	memset(dp, 0, sizeof dp);
	dp[0][0] = grid[0][0];
	for(int i=1; i<n; i++){
		dp[0][i] = dp[0][i-1] + grid[0][i];
		dp[i][0] = dp[i-1][0] + grid[i][0];
	}

	for(int i = 1; i<n; i++){
		for(int j = 1; j<n; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i][j];
		}
	}
    int ans = INT_MIN;
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			int a, b, c, d;
			a = dp[i][j];
			b = dp[i][n-1] - dp[i][j];
			c = dp[n-1][j] - dp[i][j];
			d = dp[n-1][n-1] - a - b - c;
			ans = max(ans, min( min(a, b) , min(c,d) ) );
		}
	}	
	cout<<ans;
}