// Two Sum - Leetcode

// Given an array of integers, return indices of the two numbers 
// such that they add up to a specific target.
// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.


// Link - https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            int a, b;
            a = nums[i];
            b = target - a;
            if(hash.find(b) == hash.end()){
                hash.insert({a, i});
            }
            else{
                ans.push_back(hash.at(b));
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};