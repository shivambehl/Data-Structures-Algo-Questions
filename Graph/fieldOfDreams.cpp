// Field of Dreams
// Given a Matrix of 1s and 0s, find minimum number of ones to be removed so that 1's become disconnected


#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int grid[n][m];
	memset(grid, 0, sizeof grid);

	// Maximum would be always 2 (observe)
	// 0 if more than one conneted components
	// So, the problem is to find an articulation point - the answer is 1

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			cin>>grid[i][j];
		}
	}


}