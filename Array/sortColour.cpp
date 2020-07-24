// Leetcode - Sort Colors
// Link - https://leetcode.com/problems/sort-colors/submissions/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = nums.size() -1;
        
        while(one <= two){
            if(nums[one] == 0){
                swap(nums[one++], nums[zero++]);
            }
            else if(nums[one] == 1){
                one++;
            }
            else if(nums[one] == 2){
                swap(nums[one], nums[two--]);
            }
        }
    }
};