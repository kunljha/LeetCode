class Solution {
public:
    int climbStairs(int n) { 
        vector<int> dp(n+1, 0);
        
        dp[0] = 1;
        
        for(int step = 1; step <= n; ++step) {
            int oneStep = dp[step-1];
            int twoStep = 0;
            if(step > 1) 
                twoStep = dp[step-2];

            dp[step] = oneStep + twoStep;
        }
        
        return dp[n];
    }
    
//     int fun(int step, vector<int> &dp) {
//         if(step == 0) return 1;
        
//         if(dp[step] != -1) return dp[step];
        
//         int oneStep = fun(step-1, dp);
//         int twoStep = 0;
//         if(step > 1) 
//             twoStep = fun(step-2, dp);
        
//         return dp[step] = oneStep + twoStep;
//     }
};