// really cool question
// a cook with rank a[i] cooks 1st item in a[i], 2nd in 2*a[i] etc...


#include<iostream>
using namespace std;

bool checkIfItIs(int a[], int cooks, int time, int required){
	long long res = 0;

	for(int i = 0; i < cooks; i++){
		int x = 0;
		while(a[i]*x*(x+1) <= 2*time){
			x++;
		}
		// Since It had one extra increment
		x--;
		res += x;
        //cout<<res<<endl;
	}
	return res >= required;
}


int main(){
	int n;
	cin>>n;
	int c;
	cin>>c;
	int a[c];
	for(int i = 0; i<c; i++){
		cin>>a[i];
	}
	int s = 0;
	int e;
	int x = 1;
	while(8*n*(n+1) > 2*x){
		x++; // the time it will take c cooks of highest Rank will take
	}
	e = x;

	int ans = 0;

	while(s <= e){
		int m = (s+e)/2;

		bool isThisTimeSufficient = checkIfItIs(a, c, m, n);
        //cout<<m<<" - "<<isThisTimeSufficient<<"    "<<s<<"-"<<e<<endl;
		if(isThisTimeSufficient){
			ans = m;
			e = m-1;
		}
		else{
			s = m+1;
		}
	}
	cout<<ans;
	return 0;
}