// Allocate Books - InterviewBit
// Link - https://www.interviewbit.com/problems/allocate-books/#


#include<bits/stdc++.h>
using namespace std;

bool assigningBooks(vector<int> A, int n, int m, int B){
    // we are considering it true even when I am not able to allot everyone a book
    int prev = 0;
    int cnt = 1; // Student - 1 has already been alloted first book
    for(int i = 0; i<n; i++){
        if(A[i] > m){
            return false;
        }
        if(prev + A[i] <= m){
            prev += A[i];
        }
        else{
            prev = A[i];
            cnt++;
            if(cnt > B)
                return false;
        }
    }
    return true;
}


int books(vector<int> &A, int B) {
    for(auto a: A){
        cout<<a<<" ";
    }
    cout<<endl;
    int n = A.size();
    
    int s = 0, e = 0;
    for(auto a: A){
        e += a; // e as sum of all elements
    }
    int ans = 0;
    while(s <= e){
        int m = (s + e)/2;
        bool possible = assigningBooks(A, n, m, B);
        cout<<m<<" - "<<possible<<"  "<<s<<"--"<<e<<endl;
        if(possible){
            ans = m;
            e = m - 1;
        }
        else{
            s = m + 1;
        }
    }
    return ans;
}



int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int b;
        cin>>b;
        a.push_back(b);
    }
    int s;
    cin>>s;
    cout<<books(a, s);

}