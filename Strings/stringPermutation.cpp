#include <bits/stdc++.h>
using namespace std;

vector <string> v;


void permute(string a, int l, int r)  
{  
    // Base case  
    if (l == r)  
        v.push_back(a);  
    else
    {  
        for (int i = l; i <= r; i++)  
        {  
            // Swapping done  
            swap(a[l], a[i]);
            // Recursion called  
            permute(a, l+1, r);  
            //backtrack  
            swap(a[l], a[i]);  
        }  
    }  
}  


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		sort(s.begin(),s.end());
	    do
	    {
	        std::cout << s << " ";
	    }
	    while ( std::next_permutation(s.begin(), s.end()) );
		cout<<endl;
	}
	return 0;
}
