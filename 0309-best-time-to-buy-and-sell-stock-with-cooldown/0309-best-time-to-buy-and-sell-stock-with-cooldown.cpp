class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+2, vector<int>(2, -1));
        
        return fun(0, 1, prices, dp);
    }
    
    int fun(int ind, int canBuy, vector<int> &prices, vector<vector<int>> &dp) {
        if(ind >= prices.size()) return 0;
        
        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        
        if(canBuy == 1) {
            int buy = -prices[ind] + fun(ind+1, 0, prices, dp);
            int notBuy = 0 + fun(ind+1, 1, prices, dp);
            
            return dp[ind][canBuy] = max(buy, notBuy);
        } else {
            int sell = +prices[ind] + fun(ind+2, 1, prices, dp);
            int notSell = 0 + fun(ind+1, 0, prices, dp);
            
            return dp[ind][canBuy] = max(sell, notSell);
        }
    }
};