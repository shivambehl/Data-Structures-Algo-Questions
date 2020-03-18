#include<iostream>
using namespace std;

int main(){
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int T, B, L, R;
    int n = 3;
    int m = 3;
    T = 0; B = n - 1;
    L = 0; R = m - 1;
    int dir = 0;
    while(T<=B && L<=R){
        if(dir == 0){
            for(int i = L; i<=R; i++) cout<<a[T][i]<<" ";
            T++;
        }
        else if(dir == 1){
            for(int i = T; i<=B; i++) cout<<a[i][R]<<" ";
            R--;
        }
        else if(dir == 2){
            for(int i = R; i>=L; i--) cout<<a[B][i]<<" ";
            B--;
        }
        else if(dir == 3){
            for(int i = B; i>=T; i--) cout<<a[i][L]<<" ";
            L++;
        }
        dir = (dir + 1)%4;
    }
    cout<<"\n";
    cout<<"Hello World !";
    return 0;
}