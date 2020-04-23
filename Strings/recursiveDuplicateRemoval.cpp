// Recursively remove all adjacent duplicates - geeksforgeeks
// Link - https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates/0/


#include<bits/stdc++.h>
using namespace std;

string fun(string s){
	if(s.length() < 2)
		return s;
	
	int i = 1, flag = 0;
	while(s[0] == s[i]){
		flag = 1;
		i++;
	}
	if(flag == 1){
		cout<<"1. "<<s.substr(i, s.length())<<"\n";
		return fun(s.substr(i, s.length()));
	}
	cout<<"2. "<<s[0] + fun(s.substr(1, s.length()))<<"\n";
	return s[0] + fun(s.substr(1, s.length()));
	
	// recursively claiming - 
	// s[1] + fun(2, s.length());
	// s[2] + fun(3, s.length()); ...
}



string dupl(string s){
	if(s.length() < 2)
		return s;
		
	s = fun(s);
	
	while(s != fun(s)){
		s = fun(s);
	}
	
	return s;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<dupl(s)<<endl;
	}
}
