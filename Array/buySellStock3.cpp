// LeetCode - Buy Sell Stocks 3
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0){
            return 0;
        }
        
        int left[prices.size()], right[prices.size()];
        int min_now = prices[0], max_now = prices[prices.size() - 1], ans = 0;
        left[0] = 0;
        right[prices.size() - 1] = 0;
        for(int i = 1; i<prices.size(); i++){
            left[i] = max(left[i-1], prices[i] - min_now);
            min_now = min(prices[i], min_now);
        }
        
        for(int i = prices.size() -2; i>=0; i--){
            right[i] = max(right[i+1], max_now - prices[i]);
            max_now = max(prices[i], max_now);
        }
        
        for(int i = 0; i<prices.size(); i++){
            ans = max(ans, left[i] + right[i]);
        }
        
        return ans;
    }
};