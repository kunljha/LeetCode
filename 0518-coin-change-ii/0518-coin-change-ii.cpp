class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        
        return fun(n-1, amount, coins, dp);
    }
    
    int fun(int ind, int T, vector<int> &coins, vector<vector<int>> &dp) {
        if(T == 0) return 1;
        
        if(ind == 0) return (T % coins[0] == 0);
        
        if(dp[ind][T] != -1) return dp[ind][T];
        
        int notPick = fun(ind-1, T, coins, dp);
        int pick = 0;
        
        if(coins[ind] <= T) {
            pick = fun(ind, T - coins[ind], coins, dp);
        }
        
        return dp[ind][T] = notPick + pick;    
    } 
};