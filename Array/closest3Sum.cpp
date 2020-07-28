// LeetCode - Closest 3Sum
// Link - https://leetcode.com/problems/3sum-closest/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int min_diff = INT_MAX, diff = 0, sum = 0, ans = 0;
        
        for(int k = 0; k<nums.size()-1; k++){
            int i = k+1, j = nums.size() - 1;
            
            while(i < j){
                sum = nums[i] + nums[j] + nums[k];
                diff = abs(target - sum);
                
                if(min_diff > diff){
                    min_diff = diff;
                    ans = sum;
                }
                
                if(sum < target){
                    i++;
                }
                
                else if(sum > target){
                    j--;
                }
                
                else{
                    return sum;
                }
            }
        }
        return ans;
    }
};