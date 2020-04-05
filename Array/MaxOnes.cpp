// GeeksforGeeks - Maximize Number of 1's

#include<bits/stdc++.h>
using namespace std;

int fliper(int a[], int n, int k){
	int s = 0, e = 0;
	int cnt = 0;
	int best = 0, emax = 0, smax = 0;
	for(int i=0; i<n; i++){
		if(a[e] == 0)
			cnt++;
		e++;
		while(cnt>k){
			if(a[s] == 0){
				cnt--;
			}
			s++;
		}
		if(best < e - s){
			best = e-s;
			emax = e;
			smax = s; 
		}
		
	}
	for(int i = smax; i<emax; i++){
		a[i] = 1;
	}
	return best;
}

int main() {
	int n, k;
	cin>>n>>k;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<fliper(a, n, k)<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
