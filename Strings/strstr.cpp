// Implement strstr - GeeksforGeeks
// Link - https://practice.geeksforgeeks.org/problems/implement-strstr/1
// Simple Implementation of Rabin Karp String Matching Algorithm


#include<bits/stdc++.h>
using namespace std;

int strstr(string s, string x);

int main(){
	string s, x;
	cin>>s>>x;
	cout<<strstr(s, x);
	return 0;
}

int strstr(string s, string x){
	int n = s.length();
     int m = x.length();
     
     if(n < m)
        return -1;
     
     int a = 0, b = 0;
     
     for(int i = 0; i<m; i++){
         a += s[i];
         b += x[i];
     }
     
     int st = 0, e = m-1;
     
     while(e < n){
         if(a == b){
             int flag = 0;
             for(int i = 0; i<m; i++){
                 if(s[i+st] != x[i]) flag = 1;
             }
             if(flag == 0)
                return st;
         }
         a -= s[st];
         a += s[e+1];
         st++;
         e++;
     }
     
     return -1;
}
