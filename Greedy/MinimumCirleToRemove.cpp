
// Given n Circles present in x-y plane such that all the circles have their center aligned on the x-axis.
// The task is to remove some of them, such that no two circles are intersecting. Find the minimum number of circles that need to be removed.

#include<bits/stdc++.h>
using namespace std;


bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second < b.second){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    int n;
    cin>>n;

    int r, c;
    vector<pair<int, int>> a;

    for(int i = 0; i<n; i++){
        cin>>c>>r;
        a.push_back(make_pair(c-r, c+r));
    }

    sort(a.begin(), a.end(), compare);

    int curr = INT_MAX;
    int count = 0;
    for(auto v:a){
        if(curr == INT_MAX){
            curr = v.second;
            count++;
            continue;
        }


        if(v.first >= curr){
            curr = v.second;
            count++;
        }

    }

    cout<<n - count;
    return 0;

}