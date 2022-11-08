class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n, 0);
        
        // base-case
        int prev2 = cost[0];
        int prev = cost[1];
        
        for(int step = 2; step < n; ++step) {
            int cur = cost[step] + min(prev, prev2);
            
            prev2 = prev;
            prev = cur;
        }
        
        return min(prev, prev2);
    }
    
//     int fun(int step, vector<int>& cost, vector<int> &dp) {
//         if(step < 0) return 1e9;
//         if(step == 0 || step == 1) return cost[step];
        
//         if(dp[step] != -1) return dp[step];
        
//         int costing = cost[step] + min(fun(step-1, cost, dp), fun(step-2, cost, dp));
        
//         return dp[step] = costing;
//     }
};