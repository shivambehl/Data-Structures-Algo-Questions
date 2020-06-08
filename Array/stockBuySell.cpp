// Leetcode - Stock Buy and Sell
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/



#include<bits/stdc++.h>
using namespace std;


int stockBuySell(vector<int> price){
	    int total = 0;
    	for (int i=0; i< prices.length-1; i++) {
        	if (prices[i+1]>prices[i]) total += prices[i+1]-prices[i];
    	}
    	return total;
}


int main(){
	vector<int> a;
}