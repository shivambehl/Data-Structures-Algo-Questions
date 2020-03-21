// DEFKIN - Defense of a Kingdom
// Concept Answer

#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int w, h, n;
        cin>>w>>h>>n;
        int x[n+1], y[n+1];
        
        x[n] = w+1;
        y[n] = h+1;

        for(int i = 0; i<n; i++){
            cin>>x[i]>>y[i];
        }

        sort(x, x+n+1); sort(y, y+n+1);
        int x1 = x[0], y1 = y[0];
        for(int i=1; i<n+1; i++){
            x1 = max(abs(x[i] - x[i-1]), x1);
            y1 = max(abs(y[i] - y[i-1]), y1);
        }

        cout<<(x1-1)*(y1-1)<<"\n";
    }
     
     return 0;   

}