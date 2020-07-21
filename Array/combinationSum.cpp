// LeetCode -  Combination Sum
// Link - https://leetcode.com/problems/combination-sum/


class Solution {
public:
    
    vector<vector<int> > ans;
    void get_c(vector<int> candidates, int t, int idx, vector<int> &v){
        if(t < 0)
            return;
        if(t == 0){
            ans.push_back(v);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++){
            if(i == 0 || (i > 0 && candidates[i] != candidates[i-1])){
                v.push_back(candidates[i]);
                get_c(candidates, t - candidates[i], i, v);
                v.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        get_c(candidates,  target, 0, v);
        
        return ans;
    }
};