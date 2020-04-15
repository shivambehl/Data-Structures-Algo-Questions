// matrix chain multiplication
// https://www.interviewbit.com/problems/matrix-chain-multiplication/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> A){
	int n = A.size() - 1; // number of matrices
	
	int dp[n+5][n+5];
	memset(dp, 0, sizeof dp);
	int val;
	int r, c;
	for(int i = 1; i<n; i++){
		r = 0; c = i;
		
		while(c < n){
			val = INT_MAX;
			for(int p = r; p<c; p++){
				val  = min(val, dp[r][p] + dp[p+1][c] + A[r]*A[p+1]*A[c+1]);
			}
			dp[r][c] = val;
			c++; r++;
		}
	}
	
	return dp[0][n-1];
}






int main(){
	
	int n;
	cin>>n;
	vector<int> A;
	int a;
	for(int i = 0; i<n; i++){
		cin>>a;
		A.push_back(a);
	}
	
	cout<<solve(A);
}
