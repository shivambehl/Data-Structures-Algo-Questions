// Leetcode - Interleaving String
// Link - https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    
    int dp[1000][1000];
    
    bool fun(string s1, string s2, string s3, int i, int j){
        int k = i + j;
        int n = s1.size();
        int m = s2.size();
        int p = s3.size();
        
        //cout<<i<<" "<<j<<" "<<k<<endl;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(k == p)
            return true;
        
        if(i < n && j < m && s1[i] == s3[k] && s2[j] == s3[k])
            return dp[i][j] = fun(s1, s2, s3, i+1, j) || fun(s1, s2, s3, i, j+1);
        
        if(i < n && s1[i] == s3[k])
            return dp[i][j] = fun(s1, s2, s3, i+1, j);
        
        if(j < m && s2[j] == s3[k])
            return dp[i][j] = fun(s1, s2, s3, i, j+1);
        
        
        //cout<<"Dead End"<<endl;
        return dp[i][j] = false;
        
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.size();
        int m = s2.size();
        int p = s3.size();
        
        memset(dp, -1, sizeof dp);
        if(p == 0 && n == 0 && m == 0)
            return true;
        
        if(p != n + m)
            return false;
        
        return fun(s1, s2, s3, 0, 0);
    }
};