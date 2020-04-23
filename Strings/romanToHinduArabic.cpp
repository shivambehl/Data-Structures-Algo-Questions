#include<bits/stdc++.h>
using namespace std;

map<char,int> hmap;


int convert(string s){
	if(s.size() == 1){
		return hmap[s[0]];
	}
	
	
	int i = 0, res = 0;
	while(i < s.size()){
		if(hmap[s[i]] < hmap[s[i+1]]){
			res += hmap[s[i+1]] - hmap[s[i]];
			i+=2;
		}
		else{
			res += hmap[s[i]];
			i++;
		}
	}
	return res;
}


int main(){
	
	hmap['I']=1;
	hmap['V']=5;
	hmap['X']=10;
	hmap['L']=50;
	hmap['C']=100;
	hmap['D']=500;
	hmap['M']=1000;
	
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<convert(s)<<endl;
	}
	return 0;
}
