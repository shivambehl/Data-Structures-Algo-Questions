// Concept - Fast Expontiation using Bitmasks && Modulo Formulae
// Question for Modulo Expontiation


#include <iostream>
using namespace std;

#define ll long long

ll fastModularExpontiation(ll a, ll b, ll m){
    // calculating a powered by b

    ll res = 1;
    while(b > 0){
        if(b&1){
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b = b>>1;
    }
    return res;
}

int main() {
    cout<<fastModularExpontiation(5, 3, 100);
}
