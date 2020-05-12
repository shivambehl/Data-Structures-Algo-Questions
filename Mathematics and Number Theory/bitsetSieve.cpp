// bitset sieve
// space optimised version of seive
// 8 times memory improvement

#include<iostream>
#inlcude<bitset>
#include<vector>

using namespace std;

const int n = 100005;

bitset<100005> b;
vector<int> primes;


void sieve(){
	b.set();
	b[0] = b[1] = 0;
	for(long long int i = 2; i<=n; i++){
		if(b[i]){
			primes.push_back(i);
			for(long long int j = i*i; j<=n; j++){
				b[j] = 0;
			}
		}
	}
}



int main(){
	
}
