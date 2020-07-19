// Regular Expression Matching
//Link - https://leetcode.com/problems/regular-expression-matching/

// This is bottomup solution


class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.size() + 1][p.size() + 1];
        memset(dp, false, sizeof dp);
        dp[0][0] = true;
        
        for(int j = 1; j<=p.size(); j++){
            dp[0][j] = (j>1) and p[j-1] == '*' and dp[0][j-2];
        }
        
        for(int i = 1; i<=s.size(); i++){
            for(int j = 1; j<=p.size(); j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                
                else if(p[j-1] == '*'){
                    if(dp[i][j-2] == 1){
                        dp[i][j] = 1;
                    }
                    else if(s[i-1] == p[j-2] or p[j-2] == '.'){
                        dp[i][j] = dp[i-1][j];
                    }
                }   
            }
        }
        
        return dp[s.size()][p.size()];
    }
};