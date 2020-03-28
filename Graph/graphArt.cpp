#include<bits/stdc++.h>
using namespace std;
map<pair<int, int>, list<pair<int, int>>> l;
int n, a, b, c, d;
    map<pair<int, int>, int> vec_cnt;
    map<pair<int,int>, int> visited;
int odd = 0, even = 0,p=0;
int dfs(pair<int,int> src)
{
    visited[src]=1;
    int r=(l[src].size())%2;
    for(auto x:l[src])
    {
        if(!visited[x])
        {
            r+=dfs(x);
        }
    }
    return r;
}
int main(){
    
	set<pair<int,int> > st;
    cin>>n;
    for(int i =0; i<n; i++){
        cin>>a>>b>>c>>d;
        l[make_pair(a, b)].push_back(make_pair(c, d));
        l[make_pair(c, d)].push_back(make_pair(a, b));
    }
    /*for(auto u: l){
        vec_cnt[u.first] = 0;
        
        // for(auto v: u.second){
        //     vec_cnt[u.first]++;
        // }

        vec_cnt[u.first] = u.second.size();
		st.insert(u.first);
        if(vec_cnt[u.first]%2 == 0){
            even++;
        }
        else{
            odd++;
        }
    } */
    for(auto u:l)
    {
    	st.insert(u.first);
	}

    // for(auto v: vec_cnt){
    //     cout<<v.first.first<<v.first.second<<" "<<v.second<<endl;
    // }
	
    int count = 0;
	int cnt1=0;
	int r=0;
     for(auto x:st)
        {
        	if(!visited[x])
        	{
        		cnt1++;
        		 r+=dfs(x);
			}
		}
    /*if(odd == 2 || odd == 0){
        cout<<0;
    }
    else if(odd > 2){
        while(odd > 2){
            odd-=2;
            count++;
        }
        cout<<count+cnt1;
    }*/
    cout<<max(cnt1-1,(r-1)/2);
    
    return 0;

}
