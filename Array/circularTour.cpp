// Circular Tour - GeeksforGeeks
// Link - https://practice.geeksforgeeks.org/problems/circular-tour/1


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends


/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
	int ans = 0, capacity = 0, deficit = 0;
	for(int i = 0; i<n; i++){
		capacity += p[i].patrol - p[i].distance;
		if(capacity < 0){
			deficit += capacity;
			capacity = 0;
			ans = i+1;
		}
	}
	if(capacity + deficit < 0)
		return -1;
	else
		return ans;
}
