// Check Anagrams - GeeksforGeeks
// link - https://practice.geeksforgeeks.org/problems/anagram/0

#include<bits/stdc++.h>
using namespace std;


bool fun(string s1, string s2){
    int a[256];
    
    int n = s1.length();
    int m = s2.length();
    
    memset(a, 0, sizeof(a));
    
    if(n != m) return false;
    
    for(int i=0; i<n; i++){
        a[s1[i]]++;
        a[s2[i]]--;
    }
    
    for(int i =0; i<256; i++){
        if(a[i] != 0){
            return false;
        }
    }
    
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        string s1, s2;
        cin>>s1>>s2;

        
        if(fun(s1, s2) == true){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
