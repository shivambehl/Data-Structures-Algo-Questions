// Keypad Strings
// Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/

class Solution {
public:
    
    map<char, string> cat;
    void generate_string(string digits, vector<string> &ans, int pos, string s){
        if(digits == "") // Curious case of this case(?)
            return;
        
        char digit = digits[pos];
        if(digit == '\0'){
            ans.push_back(s);
            return;
        }
        
        for(auto a: cat[digit]){
            string s1 = s + a;
            generate_string(digits, ans, pos+1, s1);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        cat['1'] = "";
        cat['2'] = "abc";
        cat['3'] = "def";
        cat['4'] = "ghi";
        cat['5'] = "jkl";
        cat['6'] = "mno";
        cat['7'] = "pqrs";
        cat['8'] = "tuv";
        cat['9'] = "wxyz";
        
        vector<string> ans;
        generate_string(digits, ans, 0, "");
        
        return ans;
    }
};