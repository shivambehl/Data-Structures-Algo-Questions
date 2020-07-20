// 3Sums
// Link - https://leetcode.com/problems/3sum/submissions/

// Insight - When you use sets to prevent duplicates, understand that sets have their own complexity/computation associated with it. Always try to minimise it

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        set<vector<int> > ans;
        
        sort(nums.begin(), nums.end());
        
        for(int k = 0; k<nums.size(); k++){
            int i = k+1, j = nums.size() - 1;
            
            
            while(i<j){
                if(nums[i] + nums[j] + nums[k] > 0)
                    j--;
                else if(nums[i] + nums[j] + nums[k] < 0)
                    i++;
                else{
                    vector<int> triplet = {nums[i], nums[j]};
                    ans.insert(triplet);
                    i++; j--;
                }
            }
            
        }
        
        for(auto a : ans){
            res.push_back({a[0], a[1], -(a[0] + a[1])});
        }
        
        return res;
    }
};