// ReplacePi
// Concept - Traversing Strring and Replacing contents using combination of iteration and recursion


#include <iostream>
using namespace std;

void replacePi(char* a, int i){
    if(a[i] == '\0' || a[i+1] == '\0'){
        return;
    }

    if(a[i] == 'p' && a[i+1] == 'i'){
        int j = i;
        while(a[j] != '\0'){
            j++;
        }
        while(j >= i+2){
            swap(a[j], a[j+2]);
            j--;
        }
        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';
        replacePi(a, j + 2);
    }
    else{
        replacePi(a, i+1);
    }

    return;
}


int main() {
    cout<<"Hello World!\n";
    char a[100];
    cin>>a;
    replacePi(a, 0);
    cout<<a;
}
