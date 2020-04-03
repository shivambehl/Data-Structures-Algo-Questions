#include<iostream>
using namespace std;

int a[100005];

void merge(int s, int e){
	int m = (s + e)/2;
	
	cout<<"Merge "<<s<<" "<<m<<" "<<e<<endl;
	
	int i = s, j = m+1, k = 0;
	int temp[e - s + 1];
	
	// filling the temp array
	while(i <= m && j <= e){
		if(a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while(i<=m)
		temp[k++] = a[i++];
	while(j<=e)
		temp[k++] = a[j++];
		
	// updating the actual array
	
	for(i=s; i<=e; i++)
		a[i] = temp[i-s];
}



void mergeSort(int s, int e){
	
	cout<<"MergeSort "<<s<<" "<<e<<endl;
	
	if(s >= e)
		return;
	
	int m = (s + e)/2;
	
	mergeSort(s, m);
	mergeSort(m+1, e);
	
	merge(s, e);
}




int main(){
	int n, i; cin>>n;
	for(i=0; i<n; i++)
		cin>>a[i];
	mergeSort(0, n-1);
	cout<<"Done"<<endl;
	for(i=0; i<n; i++)
		cout<<a[i]<<" ";
}
