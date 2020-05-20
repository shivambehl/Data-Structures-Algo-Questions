// Bubble sort Using Recursion
// Link - https://www.hackerrank.com/challenges/ctci-bubble-sort/problem

#include<iostream>
using namespace std;

int swaps = 0;

void bubble_sort(int a[], int j, int n){

    if(n == 1){
        return;
    }

    if(j == n-1){
        bubble_sort(a, 0, n-1);
        return;
    }
    if(a[j] > a[j+1]){
        swap(a[j], a[j+1]);
        swaps++;
    }
        

    bubble_sort(a, j+1, n);

    return;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    bubble_sort(a, 0, n);
    cout<<"Array is sorted in "<<swaps<<" swaps.\n";
    cout<<"First Element: "<<a[0]<<"\n";
    cout<<"Last Element: "<<a[n-1]<<"\n";
}
