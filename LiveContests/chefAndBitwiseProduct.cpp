#include<bits/stdc++.h>
using namespace std;
#define ll long  long


int main(){
	int t;
	cin>>t;
	while(t--){
		int x, y, l, r;
		cin>>x>>y>>l>>r;
		int ans = x|y;
		//cout<<"ans "<<ans<<endl;
		if(ans >=l && ans <= r){
			cout<<ans<<endl;
			continue;
		}
		int ans1, ans2;
		ans1 = ans;
		ans2 = ans;
		while(ans1 <= l ){
			int c = 1;
			int a = ans1;
			while(a){
				c = c*2;
				a >>= 1;
			}
			ans1 = ans1|c;
			//cout<<"ans1 "<<ans1<<endl;
		}
		
		while(ans2 >= r){
			int a = ans2;
			int c = 1;
			while(a){
				c = c*2;
				a>>=1;
			}
			c =c/2- 1;
			ans2 = ans2&c;
			//cout<<"ans2 "<<ans2<<endl;
		}
		if(ans2 >= l && ans2 <= r){
			cout<<ans2<<endl;
			continue;
		}
		
		cout<<ans1<<endl;
		
	}
}
