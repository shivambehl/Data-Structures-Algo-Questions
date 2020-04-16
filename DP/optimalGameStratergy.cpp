#include<bits/stdc++.h>
using namespace std;

int a[100];
int dp[100][100];



// solve using Top Down Approach
int solve(int s, int e){
	
	if(s >= e){
		return 0;
	}
	
	// id already computed
	if(dp[s][e] != -1){
		return dp[s][e];
	}
	
	int x, y, z;
	
	// three future outcomes - 
	x = solve(s+1, e-1);
	y = solve(s+2, e );
	z = solve(s, e-2 );
	
	int m, n;
	
	// case 1
	m = a[s] + min(x, y);
	
	// case 2
	n = a[e] + min(x, z);
	
	return dp[s][e] = max(m, n);
}


int solveBU(int n){
	
	for(int i = 0; i<n; i++){
		dp[i][i] = a[i]; 
	}
	int r, c;
	int x, y;
	for(int i = 1; i<n; i++){
		r = 0; c = i;
		while(c < n){
			if(c - r == 1){
				dp[r][c] = max(a[r], a[c]);
			}
			else{
				x = a[r] + min(dp[r+1][c-1], dp[r+2][c]);
				y = a[c] + min(dp[r+1][c-1], dp[r][c-2]);
				
				dp[r][c] = max(x, y);
				
				r++; c++;
			}
		}
	}
	return dp[0][n-1];	
}



int main(){
	int n;
	cin>>n;
	
	memset(dp, -1, sizeof dp);
	
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	
	//cout<<solve(0,n-1);
	
	cout<<solveBU(n);
	
//	for(int i = 0; i<n; i++){
//		for(int j = 0; j<n; j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}

}
