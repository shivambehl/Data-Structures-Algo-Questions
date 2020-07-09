// Leetcode - longest palindromic substring
// Link - https://leetcode.com/problems/longest-palindromic-substring/submissions/
// For most optimal solution - https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher's_algorithm


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 1) return "";
        int st = 0, en = 0;
        for(int i = 0; i<s.length()-1; i++){
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            int len = max(len1, len2);
            
            if(len > en - st){
                st = i - (len - 1)/2;
                en = i + len/2;
            }
        }
        
        return s.substr(st, en - st + 1);
        
    }
    
    int expand(string s, int left, int right){
        int l, r;
        l = left;
        r = right;
        
        while(l>=0 and r<=s.size() and s[l] == s[r]){
            l--; r++;
        }
        
        return r - l - 1;
    }
    
};