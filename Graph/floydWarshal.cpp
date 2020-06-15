#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int g[n+1][n+1]; // adjecency matrix representation of graph

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin>>g[i][j];
		}
	}

	// now we will use graph g as distance matrix
	for(int k = 1; k<=n; k++){
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=n; j++){
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	cout<<"Your All Pair Shortest Path matrix is ready";

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cout<<g[i][j]<<"\t";
		}
		cout<<"\n";
	}


}