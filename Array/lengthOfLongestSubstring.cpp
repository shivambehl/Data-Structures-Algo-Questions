// Longest Substring Without Repeating Characters - LeetCode
// Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
Given a string, find the length of the longest substring without repeating characters
*/


// Editorial is Good, do check out



int lengthOfLongestSubstring(string s) {
        bool hash[256];
        memset(hash, false, sizeof hash);
        int st=0, en=0, maxLen=0;
        for(int i = 0; i<s.size(); i++){
            //cout<<i<<endl;
            en = i;
            if(hash[s[i]] == false){
                hash[s[i]] = true;
            }
            else{
                while(hash[s[i]] == true && st <= en){
                    hash[s[st]] = false;
                    //cout<<"st "<<st<<" "<<hash[s[i]]<<" "<<hash[s[st]]<<" "<<i<<endl;
                    st++;
                }
                
                hash[s[i]] = true;
            }
            
            
            maxLen = max(maxLen, en - st + 1);
            //cout<<maxLen<<endl;
        }
        return maxLen;
    }