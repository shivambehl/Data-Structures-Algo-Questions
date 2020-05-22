// generate all subsequences of input string

#include<bits/stdc++.h>
using namespace std;

void subseq(char* a, char* out, int i, int j){
    if(a[i] == '\0'){
        out[j] = '\0';
        cout<<out<<" ";
        return;
    }
    subseq(a, out, i+1, j);
    out[j] = a[i];
    subseq(a, out, i+1, j+1);
    return;
}


int main(){
    char a[10];
    cin>>a;
    char b[10];

    subseq(a, b, 0, 0);

    return 0;
}