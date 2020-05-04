// Segmented Prime Sieve
// PRIME1 - SPOJ

#include<iostream>
#include<vector>
using namespace std;

const int N = 100000;

vector<int> primes;

int p[N] = {0};

void sieve(){
	for(int i = 2; i<N; i++){
		primes.push_back(i);
		if(p[i] == 0){
			for(int j = i; j<N; j+=i){
				p[j] = 1; // Not Prime
			}
		}
	}
}


int main(){
	sieve();
	
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>m>>n;
		
		bool segment[n-m+1];
		
		for(int i=0; i<n-m+1; i++){
			segment[i] = 0; // Prime
		}

		for(auto x:primes){
			
			if(x*x>n){
				break;
			}
			
			int start = (m/x)*x;
			
			if(x>=m and x<=n){
				start = x*2;
			}

            //if(start < m) start = start + 2;
			for(int i = start; i<=n; i+=x){

                //cout<<"Dummy"<<i-m<<endl;
				segment[i-m] = 1;
			}
		}
		
		for(int i = m; i<=n; i++){	
		    if(segment[i-m] == 0 && i != 1){
			    cout<<i<<endl;
            }
	    }
	
		cout<<endl;
	}
	
	
	return 0;
}






