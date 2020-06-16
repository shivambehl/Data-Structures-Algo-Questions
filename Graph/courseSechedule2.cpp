// Leetcode - Course Sechedule - II
// Link - https://leetcode.com/problems/course-schedule-ii/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int indeg[numCourses];
        int n = numCourses;
        list<int> adj[n];
        
        memset(indeg, 0, sizeof indeg);
        for(auto v : prerequisites){
            adj[v[1]].push_back(v[0]);
            indeg[v[0]]++;
        }

        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto nb : adj[u]){
                indeg[nb]--;
                if(indeg[nb] == 0)
                        q.push(nb);
            }
        }
        
        if(ans.size() == numCourses)
            return ans;
        
        else{
            vector<int> HereIsEmptyVec;
            return HereIsEmptyVec;
        }
    }
};