// GeeksforGeeks - Inversion of array
// https://practice.geeksforgeeks.org/problems/inversion-of-array/0


#include <bits/stdc++.h>
using namespace std;

#define ll long long


ll merge(ll *a, ll s, ll e){
    ll m = (s+e)/2;
    ll i=s;
    ll j=m+1;
    ll k=0;

    ll temp[e - s + 1];

	ll invCount = 0;

    while(i<=m && j<=e){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
			invCount += m - i + 1;
        }
    }

    while(i<=m){
        temp[k++] = a[i++];
    }

    while(j<=e){
        temp[k++] = a[j++];
    }

    for(ll i=s; i<=e; i++){
        a[i] = temp[i-s];
    }

	//cout<<s<<" "<<e<<" "<<m<<" Inv : "<<invCount<<endl;

	return invCount;
}



ll mergesort(ll a[], ll s, ll e){
    if(s>=e){
        return 0;
    }
	
    ll m = (s+e)/2;
	
	ll invCount = 0;

    invCount += mergesort(a, s, m);
    invCount += mergesort(a, m+1, e);

	invCount += merge(a, s, e);

    return invCount;
}


int main() {
    int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		cout<<mergesort(a, 0, n-1)<<endl;
	}
}
