// Validate an IP Address - GeeksForGeeks
// https://practice.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1/
// Not Accepted - Abort signal from abort(3) (SIGABRT)

#include<bits/stdc++.h>
using namespace std;


int check(char *ip_str) 
{
    if(ip_str == NULL)
        return 0;
	char* ptr = ip_str;
	int n = 0;
    while (*ip_str) { 
    	n++;
        if (*ip_str >= '0' && *ip_str <= '9') 
            ++ip_str; 
        else
            return 0; 
    } 
    if(n > 1 && *ptr == '0')
		return 0;
    return 1; 
}


int isValid(char *ip) {
    
    if(ip == NULL)
        return 0;
    
    char* ptr = strtok(ip, ".");
    int segments = 0;
    while(ptr){
    	segments++;
		if(ptr == NULL) return 0;
		
		if(!check(ptr)){
			return 0;
		}
		
		if(stoi(ptr) < 0 || stoi(ptr) > 255)
			return 0;
    	
    	ptr = strtok(NULL, ".");
	}
    if(segments != 4)
    	return 0;
    
    return 1;
}

int main(){
	char ip[1000];
	cin>>ip;
	cout<<isValid(ip);
}
