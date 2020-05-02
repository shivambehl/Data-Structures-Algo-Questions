#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[256];
		memset(a, 0, sizeof(a));
		queue<char> q;
		
		for(int i = 0; i<n; i++){
			char c;
			cin>>c;
			a[c]++;
			
			//if(a[c] == 1)
				q.push(c);
			
			while(!q.empty() && a[q.front()] > 1){
				q.pop();
			}
			
			if(q.empty()){
				cout<<-1<<" ";
			}
			else{
				cout<<q.front()<<" ";
			}
		}
		
		cout<<endl;
	}
}
