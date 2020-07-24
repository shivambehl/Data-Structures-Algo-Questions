// Wiggle Sort / Wave Sort
// Link - https://leetcode.com/problems/wiggle-sort-ii/submissions/


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        /*
        for(int i = 1; i<nums.size(); i = i+2){
            // so we are at even positioned element
            
            if(i != 0 && nums[i] < nums[i-1]){
                swap(nums[i], nums[i-1]);
            }
            
            else if(i != nums.size() - 1 && nums[i] < nums[i+1]){
                swap(nums[i], nums[i+1]);
            }
            
        }
        */
        
        vector<int> val = nums;
        int last = nums.size()  - 1;
        sort(val.begin(), val.end());
        
        
        for(int i = 1; i<nums.size(); i+=2){
            nums[i] = val[last--];
        }
        for(int i = 0; i<nums.size(); i+=2){
            nums[i] = val[last--];
        }
        
    }
};