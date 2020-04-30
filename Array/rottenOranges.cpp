#include<bits/stdc++.h>
using namespace std;

int m[101][101];
int r, c;


int rot(int i, int j, int s){ // s -> starting time

		//cout<<"Charms "<<i<<" "<<j<<" "<<s<<endl;
		int a = 0, b = 0, k = 0, d = 0;
		if(m[i-1][j] == 1 && i > 0 ){
			m[i-1][j] = 2;
			a = rot(i-1, j, s+1);
		}
		if(m[i][j-1] == 1 && j > 0){
			m[i][j-1] = 2;
			b = rot(i, j-1, s+1);
		}
		if(m[i+1][j] == 1 && i+1 < r){
			m[i+1][j] = 2;
			k = rot(i+1, j, s+1);
		}
		if(m[i][j+1] == 1 && j+1 < c){
			m[i][j+1] = 2;
			d = rot(i, j+1, s+1);
		}
		return s += max(a, max(b, max(k, d)));
}



int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>r>>c;
		memset(m, 0, sizeof m);
		for(int i = 0; i<r; i++){
			for(int j = 0; j<c; j++){
				cin>>m[i][j];
			}
		}
		
		int mx = INT_MIN;
		for(int i = 0; i<r; i++){
			for(int j = 0; j<c; j++){
				if(m[i][j] == 2){
					mx = max(mx, rot(i, j, 0));
				}
			}
		}
		int flag = 0;
		for(int i = 0; i<r; i++){
			for(int j = 0; j<c; j++){
				if(m[i][j] == 1){
					flag = 1;
					break;
				}
			}
		}
		
		if(flag == 1)
			cout<<-1;
		else
			cout<<mx;
			
		cout<<endl;
		
	}
}
