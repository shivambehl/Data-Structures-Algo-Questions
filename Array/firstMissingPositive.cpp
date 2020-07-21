// First Missing Positive
// Link - https://leetcode.com/problems/first-missing-positive/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int val = 0;
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            if(nums[i] <= 0 || nums[i] > n)
                continue;
            
            val = nums[i];
            
            while(nums[val - 1] != val){
                int val1 = nums[val - 1];
                nums[val - 1] =  val;
                val = val1;
                if(val <= 0 || val > n)
                    break;
            }
        }
        int i = 0;
        for(i = 0; i<n; i++){
            if(nums[i] != i+1)
                break;
        }
        return i + 1;
    }
};