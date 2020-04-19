// longest bracket ballenced substring

#include<bits/stdc++.h>
using namespace std;

int main() {
	char a[100001];
	cin>>a;
	int n = strlen(a);
	stack<int> s;
	s.push(-1);
	int mx = INT_MIN;
	for(int i = 0; i<n; i++){
		if(a[i] == '('){
			s.push(i);
		}
		else if(a[i] == ')')
			s.pop();
		if(s.empty() == true)
			s.push(i);
		mx = max(mx, i - s.top());
	}
	cout<<mx;
	return 0;
}
