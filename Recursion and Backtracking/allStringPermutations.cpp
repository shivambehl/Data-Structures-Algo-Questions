// backtracking concept
// generate all permutations of a string

#include<iostream>
#include<set>
#include<string>
using namespace std;

void permute(char* in, int i, set<string> &s){
    // base case
    if(in[i] == '\0'){
        string str(in);
        s.insert(str);
        return;
    }
    // recursive case
    for(int j = i; in[j] != '\0'; j++){
        swap(in[i], in[j]);
        permute(in, i+1, s);
        swap(in[i], in[j]);
    }
    return;
}



int main(){
    char a[] = "abb";
    set<string> s;
    permute(a, 0, s);

    for(auto a: s){
        cout<<a<<", ";
    }
}