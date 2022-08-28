class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        
        return func(n, dp);
    }
    
    int func(int n, vector<int> &dp) {
        if(n < 0) return 0;
        
        if(n == 0) return dp[n] = 1;
        
        if(dp[n] != 0) return dp[n];
        
        return dp[n] = func(n-1, dp) + func(n-2, dp);
    }
};