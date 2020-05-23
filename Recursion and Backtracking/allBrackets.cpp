// print all strings with n balanced pairs of paranthesis

#include<bits/stdc++.h>
using namespace std;

void count(int n, int pos, int open, int close){
    static char str[24];
    if(pos == 2*n){
        cout<<str<<endl;
    }
    else{
        if(open > close){
            str[pos] = ')';
            count(n, pos + 1, open, close + 1);
        }
        if(open < n){
            str[pos] = '(';
            count(n, pos+1, open + 1, close);
        }
    }
}


int main() {
	int n;
    cin>>n;
    count(n, 0, 0, 0);
	return 0;
}