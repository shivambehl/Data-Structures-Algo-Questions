// LeetCode - Jump Game
// Link - https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int leftMostTrue = n-1;
        
        for(int i = n-1; i>=0; i--){
            if(nums[i] + i >= leftMostTrue){
                leftMostTrue = i;
            }
        }
        
        return leftMostTrue == 0;
    }
};