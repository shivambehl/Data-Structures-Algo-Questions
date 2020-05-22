// generate all possible strings from the given string of numbers


#include <bits/stdc++.h>
using namespace std;

char mag[] = ".abcdefghijklmniopqrstuvwx";
// used a . buffer so to make index of a as 1


void string_generator(char* a, char* out, int i, int j){
    if(a[i] == '\0'){
        out[j] = '\0';
        cout<<out<<"\n";
        return;
    }
    if(a[i+1] != '0' || i + 1 == strlen(a)){
        out[j] = mag[a[i] - '0'];
        string_generator(a, out, i+1, j+1);
    }

    int num = ((a[i]-'0')*10 + (a[i+1] - '0'));
    if( num<26 && strlen(a) != i + 1){
        out[j] = mag[num];
        string_generator(a, out, i+2, j+1);
    }

    return;
}



int main() {
    char a[] = "1234";
    char out[100];
    string_generator(a, out, 0, 0);

    // 1 2 3 4
    // 12 3 4
    // 1 23 4

}
