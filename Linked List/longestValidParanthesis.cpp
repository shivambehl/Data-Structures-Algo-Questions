// Longest Valid Parenthesis
// Link - https://leetcode.com/problems/longest-valid-parentheses/


class Solution {
public:
    int longestValidParentheses(string s) {
        if(s == "")
            return 0;
        int n = s.size();
        stack<int> st;
        st.push(-1);
        int mx = 0;
        for(int i = 0; i<n; i++){           
            
            if(s[i] == ')'){
                st.pop();
                if(!st.empty())
                    mx = max(mx, i - st.top());
                else
                    st.push(i);
            }
            
            else{
                if(st.empty())
                    st.push(-1);
                st.push(i);
            }
                
        }
        
        return mx;
    }
};