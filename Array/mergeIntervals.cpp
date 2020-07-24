// Leetcode - Merge Intervals
// Link - https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    
    static bool compare(vector<int> a, vector<int> b){
        if(a[0] < b[0])
            return true;
        else if(a[0] == b[0] && a[1] > b[1])
            return true;
        return false;
    }
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > mer;
        if(intervals.empty())
            return mer;
        sort(intervals.begin(), intervals.end(), compare);
        mer.push_back(intervals[0]);
        int last = 0;
        for(int i = 1; i<intervals.size(); i++){
            if(mer.empty() || mer[last][1] < intervals[i][0]){
                mer.push_back(intervals[i]);
                last++;
            }
            else{
                mer[last][1] = max(mer[last][1], intervals[i][1]);
            }
        }
        
        return mer;
    }
};