// Print all possible subsets of array whose sum is equal to K


#include<bits/stdc++.h>
using namespace std;

set<vector<int>> s;


void printVector(vector<int> V){
    for(int i = 0; V[i] != -1; i++){
        cout<<V[i]<<" ";
    }
    cout<<endl;
}


void sumItUp(int a[], vector<int> out, int i,int j, int sum){
	if(sum == 0){
        out[j] = -1;
		for(int I = 0; I<j; I++){
			s.insert(out);
		}
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
    s.clear();
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	int sum;
	cin>>sum;
	sort(a, a+n);
	vector<int> out(20);
	sumItUp(a, out, 0,0, sum);
    
    //cout<<s.size()<<endl;
    for(auto it = s.begin(); it!=s.end(); it++){
        printVector(*it);
    }

	return 0;
}