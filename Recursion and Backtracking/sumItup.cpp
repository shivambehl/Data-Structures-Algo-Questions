#include<bits/stdc++.h>
using namespace std;

se<vector<int>> s;


void printVector<>


void sumItUp(int a[], vector<int> out, int i,int j, int sum){
	if(sum == 0){
		for(int I = 0; I<j; I++){
			s.insert(out);
		}
		cout<<endl;
		return;
	}
	if(a[i] > sum){
		return;
	}
	out[j] = a[i];
	sumItUp(a, out, i+1, j+1, sum - a[i]);
    sumItUp(a, out, i+1, j, sum);
	return;
}


int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	int sum;
	cin>>sum;
	sort(a, a+n);
	vector<int> out[100];
	sumItUp(a, out, 0,0, sum);

    

	return 0;
}