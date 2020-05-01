// Rotton Oranges - GeeksforGeeks, LeetCode
// Link -> https://practice.geeksforgeeks.org/problems/rotten-oranges/0
// Link -> https://leetcode.com/problems/rotting-oranges/ (Not Submitted Yet)


#include<bits/stdc++.h>
using namespace std;

int m[101][101];
int r, c;


bool check(int a, int b){
	if(a >= r || a < 0
	|| b >= c || b < 0){
		return false;
	} 
	else
		return true;
}


int fun(){
	int count = 0;
	pair<int, int> del = make_pair(-1, -1);
	queue<pair<int, int> > q;
	for(int i = 0; i<r; i++){
		for(int j = 0; j<c; j++){
			if(m[i][j] == 2){
				q.push(make_pair(i, j));
			}
		}
	}
	
	q.push(del);
	
	while(!q.empty()){
		while(!q.empty() && q.front() != del){
			pair<int, int> a = q.front();
			q.pop();
			
			if(check(a.first -1, a.second) && m[a.first - 1][a.second] == 1){
				q.push(make_pair(a.first - 1, a.second));
				m[a.first -1][a.second] = 2;
				
				//cout<<"("<<a.first<<","<<a.second<<")"<<" -> "<<1<<endl;
			}
				
				
			if(check(a.first + 1, a.second) && m[a.first + 1][a.second] == 1){
				q.push(make_pair(a.first + 1, a.second));
				m[a.first + 1][a.second] = 2;
				
				//cout<<"("<<a.first<<","<<a.second<<")"<<" -> "<<2<<endl;
			}
				
			
			if(check(a.first, a.second - 1) && m[a.first][a.second - 1] == 1){
				q.push(make_pair(a.first, a.second - 1));
				m[a.first][a.second -1] = 2;
				
				//cout<<"("<<a.first<<","<<a.second<<")"<<" -> "<<3<<endl;
			}
				
			
			if(check(a.first, a.second + 1) && m[a.first][a.second + 1] == 1){
				q.push(make_pair(a.first, a.second + 1));
				m[a.first][a.second +1 ] = 2;
				
				//cout<<"("<<a.first<<","<<a.second<<")"<<" -> "<<4<<endl;
			}
				
		}
		
		if(!q.empty() && q.front() == del ){
			q.pop();
			
			if(!q.empty()){
				count++;
				q.push(del);
			}
				
		}
	}
	return count;	
}



int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>r>>c;
		memset(m, 0, sizeof m);
		for(int i = 0; i<r; i++){
			for(int j = 0; j<c; j++){
				cin>>m[i][j];
			}
		}
		
//		for(int i = 0; i<r; i++){
//			for(int j = 0; j<c; j++){
//				cout<<m[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		
		
		int mx = fun();
		
		
//		for(int i = 0; i<r; i++){
//			for(int j = 0; j<c; j++){
//				cout<<m[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		
		
		int flag = 0;
		for(int i = 0; i<r; i++){
			for(int j = 0; j<c; j++){
				if(m[i][j] == 1){
					flag = 1;
					break;
				}
			}
		}
		
		if(flag == 1)
			cout<<-1;
		else
			cout<<mx;
			
		cout<<endl;
		
	}
}
