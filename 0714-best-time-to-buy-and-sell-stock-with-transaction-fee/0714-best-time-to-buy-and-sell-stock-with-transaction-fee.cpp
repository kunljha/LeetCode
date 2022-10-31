class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return fun(0, 1, prices, fee, dp);
    }
    
    int fun(int ind, int buy, vector<int> &prices, int fee, vector<vector<int>> &dp) {
        if(ind == prices.size()) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy == 1) {
            int buyProfit = -prices[ind] + fun(ind+1, 0, prices, fee, dp);
            int notBuyProfit = 0 + fun(ind+1, 1, prices, fee, dp);
            
            return dp[ind][buy] = max(buyProfit, notBuyProfit);
        } else {
            int sellProfit = prices[ind] - fee + fun(ind+1, 1, prices, fee, dp);
            int notSellProfit = 0 + fun(ind+1, 0, prices, fee, dp);
            
            return dp[ind][buy] = max(sellProfit, notSellProfit);
        }
    }
};