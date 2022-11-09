class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 0);
        
        dp[0] = nums[0];
        
        for(int ind = 1; ind < n; ++ind) {
            int notRobbed = 0 + dp[ind-1]; 
            
            int robbed = nums[ind];
            if(ind > 1) robbed += dp[ind-2];

            dp[ind] = max(robbed, notRobbed);
        }

        return dp[n-1];
    }
    
//     int fun(int ind, vector<int> &nums, vector<int> &dp) {
//         if(ind < 0) return 0;
//         if(ind == 0) return nums[0];
        
//         if(dp[ind] != -1) return dp[ind];
        
//         int robbed = nums[ind] + fun(ind-2, nums, dp);
//         int notRobbed = 0 + fun(ind-1, nums, dp);
        
//         return dp[ind] = max(robbed, notRobbed);
//     }
};