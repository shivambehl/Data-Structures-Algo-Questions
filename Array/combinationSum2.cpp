// Combination Sum 2
// Link - https://leetcode.com/problems/combination-sum-ii/


class Solution {
public:
    
    set<vector<int>> ans;
    
    void fun(vector<int> c, int t, int idx, vector<int> &v){
        if(t < 0)
            return;
        
        if(t == 0){
            ans.insert(v);
            return;
        }
        
        for(int i = idx; i<c.size(); i++){
            
            
                v.push_back(c[i]);
                fun(c, t - c[i], i+1, v);
                v.pop_back();
            
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        fun(candidates, target, 0, v);
        
        vector<vector<int>> res;
        for(auto a: ans){
            res.push_back(a);
        }
        
        return res;
    }
};