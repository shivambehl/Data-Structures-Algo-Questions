// Sparse Table - Advanced CP concepts
// link - https://cp-algorithms.com/data_structures/sparse-table.html#:~:text=Sparse%20Table%20is%20a%20data,in%20O(1)%20time.
// Not tested yet


#include<bits/stdc++.h>
using namespace std;


class sparse_table{
	vector<vector<int> > mat;
	vector<int> p2;
	int n, m;

	void init(int _n, int _m){
		n = _n; m = _m; // size and log
		mat.resize(n);
		p2.resize(n + 1);
		for(int i = 0; i<n; i++){
			mat[i].resize(m);
		}
		for(int i = 0; i<=n; i++){
			p2[i] = p2[i/2] + 1; // power of 2 vector
		}
	}

	void build(int a[]){
		for(int i = 0; i<n; i++){
			mat[i][0] = a[i];
		}
		for(j = 1; j<m; j++){
			for(int i = 0; i+ (1 + << j) <= n; i++){
				mat[i][j] = min(mat[i][j-1], mat[i+(1<<(j-1))][j-1]);
			}
		}
	}

	int query(int l, int r){
		int pw = p2[r - l];
		return min(mat[l][pw], mat[r-(1<<pw) + 1][pw]);
	}

}


void solve(){
	int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
}


int main(){

}