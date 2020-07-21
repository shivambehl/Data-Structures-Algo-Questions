// Generate Paranthsis
// Link - https://leetcode.com/problems/generate-parentheses/

// Focus on

class Solution {
public:
    
    void backtrack(vector<string> &ans, string s, int open, int close, int n){
        if(s.size() == n*2){
            ans.push_back(s);
            return;
        }
        if(open < n) // This
            backtrack(ans, s + '(', open + 1, close, n);
        if(close < open) // and This
            backtrack(ans, s + ')', open, close + 1, n);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0) return ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
};