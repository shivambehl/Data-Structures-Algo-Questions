// Leetcode - Trapping Rainwater
// Link - https://leetcode.com/problems/trapping-rain-water/


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        if(n==0) return 0;
        
        int left[n], right[n];
        
        left[0] = 0;
        right[n-1] = 0;
        
        for(int i = 1; i<n; i++){
            left[i] = max(left[i-1], height[i-1]);
        }
        for(int i = n-2; i>-1; i--){
            right[i] = max(right[i+1], height[i+1]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            
            ans += (min(left[i], right[i]) - height[i] > 0)? min(left[i], right[i]) - height[i] : 0; 
            
        }
        return ans;
    }
};