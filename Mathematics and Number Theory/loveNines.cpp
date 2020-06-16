// I have no proof of whether this is correct or not
// Given a number N, find out minimum number of numbers needed whose last digit is 9 to make sum N. Output -1 if not possible
// {asked in CodeAgon}

/*
My thought behined the solution - 

every number when added will add a factor of 9 behind it.
so I am just removing those factors of 9 till I get a number ending with 9
in the testcases that  made, it takes at max the number of digits I used to make input number

Anyone, if knows the original answer or know a counter example to prove this solution wrong, your feedback will be much appreciated.

*/



#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	count = 1;
	while(n%10 != 9 && n > 0){
		n - 9;
		count++;
	}

	if(n < 0){
		cout<<"-1";
	}
	else{
		cout<<count;
	}
}