// find sum of length of all subarray of distinct elements from given array

#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	
	set<int> s;
	int i = 0, j = 0;
	int sum = 0;
	int count = 0;
	
	while(i <= j){
		while(j < n && s.find(a[j]) == s.end()){
			s.insert(a[j]);
			j++;
		}
		cout<<i<<" "<<j<<endl;
		count = j - i;
		sum += count*(count+1)/2;
		s.erase(a[i]);
		i++;
	}
	
	cout<<sum%mod;
	
	return 0;
}
