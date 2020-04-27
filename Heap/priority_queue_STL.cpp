// Using Priority Queue STL

#include<iostream>
#include<queue>
using namespace std;


class person{
	public:
		string name;
		int age;
		
	person(string n, int a){
		name = n;
		age = a;
	}
};


class comparePerson{
	public:
		bool operator() (person A, person B){
			return A.age < B.age;
		}
};

int main(){
	
//	priority_queue<int> max_priority_queue;
//	priority_queue<int, vector<int>, greater<int> > pq;
//	int n;
//	cin>>n;
//	for(int i = 0; i<n; i++){
//		int no;
//		cin>>no;
//		pq.push(no);
//	}
//	
//	while(!pq.empty()){
//		cout<<pq.top()<<" ";
//		pq.pop();
//	}
	
	
	///////////////////////////////////////////////////////////
	
	
	priority_queue<person, vector<person>, comparePerson> ppq;
	int n;
	cin>>n;
	for(int i = 0; i<n; i++){
		string name; int age;
		cin>>name>>age;
		person p(name, age);
		ppq.push(p);
	}
	
	int k = 2;
	
	for(int i = 0; i<k; i++){
		person p = ppq.top();
		cout<<p.name<<" "<<p.age<<endl;
		ppq.pop();
	}
	
	return 0;
}
