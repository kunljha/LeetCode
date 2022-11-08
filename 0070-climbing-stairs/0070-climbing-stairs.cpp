class Solution {
public:
    int climbStairs(int n) { 
        vector<int> dp(n+1, -1);
        return fun(n, dp);
    }
    
    int fun(int step, vector<int> &dp) {
        if(step == 0) return 1;
        
        if(dp[step] != -1) return dp[step];
        
        int oneStep = fun(step-1, dp);
        int twoStep = 0;
        if(step > 1) 
            twoStep = fun(step-2, dp);
        
        return dp[step] = oneStep + twoStep;
    }
};