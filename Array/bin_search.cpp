// binary search

#include<iostream>
using namespace std;

int binary_search(int arr[], int key){
	int size = sizeof(arr)/sizeof(arr[0]);
	int s, e, m;
	s = 0; 
	e = size - 1;
	
	
	while(s<=e){
		
		int mid = (s + e)/2;
		
		if(arr[mid] == key) return mid;
		
		else if(arr[mid] > key){
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
		
	}
	
	
	return -1;
	
}


int main(){
	int arr[] = {1, 2, 3, 4, 6, 7, 88};
	cout<<binary_search(arr, 4)<<endl;
	cout<<binary_search(arr, 1)<<endl;
	cout<<binary_search(arr, 4)<<endl;
}
