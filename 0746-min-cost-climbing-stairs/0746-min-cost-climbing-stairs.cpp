class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int> dp(n, -1);
        
        return min(fun(n-1, cost, dp), fun(n-2, cost, dp));
    }
    
    int fun(int step, vector<int>& cost, vector<int> &dp) {
        if(step < 0) return 1e9;
        if(step == 0 || step == 1) return cost[step];
        
        if(dp[step] != -1) return dp[step];
        
        int costing = cost[step] + min(fun(step-1, cost, dp), fun(step-2, cost, dp));
        
        return dp[step] = costing;
    }
};