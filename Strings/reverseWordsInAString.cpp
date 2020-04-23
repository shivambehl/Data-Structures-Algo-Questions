#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    char str[2001];
	    cin>>str;
	    vector<string> a;
		char* ptr = strtok(str, ".");
		while(ptr != NULL){
			a.push_back(ptr);
			ptr = strtok(NULL, ".");
		}
		for(int i=a.size()-1; i>=0; i--){
			cout<<a[i];
			if(i!=0)
				cout<<".";
		}
		
		cout<<endl;
	}
	return 0;
}
