// Integer Break - Leetcode -  Dynamic programming

// https://leetcode.com/problems/integer-break/

// Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

// Return the maximum product you can get.

// Input: n = 10
// Output: 36
// Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.


// An interesting alternate approach:
// https://leetcode.com/problems/integer-break/discuss/80689/A-simple-explanation-of-the-math-part-and-a-O(n)-solution




class Solution {
public:
    int integerBreak(int n) {
        
        int dp[n+2];
        memset(dp, 0, sizeof dp);
        
        
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i = 3; i<=n; i++){
            for(int j = 1; j<i; j++){
                int ini = max(j * (i - j), j*dp[i - j]);
                
                cout<<dp[i]<<" "<<ini<<endl;
                dp[i] = max(ini, dp[i]);
            }
        }
        
        return dp[n];
    }
};