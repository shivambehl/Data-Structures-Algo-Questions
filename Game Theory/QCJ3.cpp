// SPOJ - QCJ3 - The Game
// https://www.spoj.com/problems/QCJ3/

// Game Theory
// This is a question of Game of Nim
// Every coin is equivilent of a Nim Pile, and its height is its Index.
// Square with even coins will contribute zero and square with odd coins will contribute equal to index.

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int s;
		cin>>s;
		int a;
		long long int x = 0;
		for(int i = 1; i<=s; i++){
			cin>>a;
			if(a%2) x = x^i;
		}
		if(x != 0)
			cout<<"Tom Wins"<<endl;
		else
			cout<<"Hanks Wins"<<endl;
	}
	return 0;
}
