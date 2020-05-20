#include <iostream>
using namespace std;


int fast_power(int a, int b){
    // to compute a raised to the power b using recursion

    if(b == 0)
        return 1;

    int sm = fast_power(a, b/2);

    sm = sm*sm;
    if(b&1){
        return a*sm;
    }
    return sm;
}


int main() {
    int a = 2;
    int b = 10;

    cout<<fast_power(a, b);
}
