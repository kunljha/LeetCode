class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
            
        int ans = fun(n-1, amount, coins, dp);
        
        if(ans >= 1e9) return -1;
        
        return ans;
    }
    
    int fun(int ind, int T, vector<int> &coins,  vector<vector<int>> &dp) {
        if(T == 0) return 0;
        if(ind == 0) {
            if(T % coins[0] == 0) return T / coins[0];
            else return 1e9;
        }
        
        if(dp[ind][T] != -1) return dp[ind][T];
        
        int notPick = 0 + fun(ind-1, T, coins, dp);
        int pick = 1e9;
        if(coins[ind] <= T) {
            pick = 1 + fun(ind, T - coins[ind], coins, dp);
        }
        
        return dp[ind][T] = min(notPick, pick);
    }
};