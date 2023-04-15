class Solution {
public:
    // memoization
    int maxValueOfCoins(vector<vector<int>>& pile, int k) {
        int n = pile.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        
        return fun(0, pile, k, dp);
    }
    
    int fun(int ind, vector<vector<int>> &pile, int k, vector<vector<int>> &dp) {
        if(ind == pile.size()) return 0;
        
        if(dp[ind][k] != -1) return dp[ind][k]; 
        
        int max_sum = 0;
        
        // not-pick coins from ind-th pile
        max_sum = max(max_sum, fun(ind+1, pile, k, dp));
        
        // pick coins from ind-th pile
        int cur_sum = 0;
        for(int i = 0; i < pile[ind].size(); ++i) {
            cur_sum += pile[ind][i];
            
            // decide to pick remaining coins from next pile
            if(k-(i+1) >= 0)
                max_sum = max(max_sum, cur_sum + fun(ind+1, pile, k-(i+1), dp));
            
        }
          
        return dp[ind][k] = max_sum;
    }
    
    // approach : https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/discuss/1887130/C%2B%2B-or-DP-%2B-Memoization
    
    
};