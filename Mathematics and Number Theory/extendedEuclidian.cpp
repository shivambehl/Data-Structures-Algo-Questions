// To Solve Equations Like - Ax + By = GCD(A, B)

#include <iostream>
using namespace std;


int x, y, GCD;
void extendedEuclidian(int a, int b){
    if(b == 0){
        x = 1;
        y = 0;
        GCD = a;
        return;
    }

    extendedEuclidian(b, a%b);

    int Cx = y;
    int Cy = x - (a/b)*y;

    x = Cx;
    y = Cy;

    return;
}

int main() {
    extendedEuclidian(18, 30);
    cout<<x<<" "<<y;

    //cout<<endl<<18%30;

    return 0;
}
