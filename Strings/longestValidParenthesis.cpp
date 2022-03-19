// 32. Longest Valid Parentheses - Leetcode

// https://leetcode.com/problems/longest-valid-parentheses/

// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.


class Solution {
public:
    int longestValidParentheses(string s) {
        
        
        stack<int> st;
        
        st.push(-1);
        
        int ans = 0;
        
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(')
                st.push(i);
            
            else if(s[i] = '(' && st.size() > 1){
                st.pop();
                ans = max(ans, i - st.top());
            }
            
            else{
                st.pop();
                st.push(i);
            }    
        }
        
        return ans;
        
    }
};