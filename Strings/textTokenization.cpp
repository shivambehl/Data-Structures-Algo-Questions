#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[] = "Today is a fine day !";

    char * ptr = strtok(s, " ");

    while(ptr != NULL){
        cout<<ptr<<endl;
        ptr = strtok(NULL, " ");
    }

    return 0;    
}
