class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // vector<int> dp(n, 0);
        int prev2 = 0, prev = nums[0];
        
        for(int ind = 1; ind < n; ++ind) {
            int notRobbed = 0 + prev; 
            
            int robbed = nums[ind];
            if(ind > 1) robbed += prev2;

            int cur = max(robbed, notRobbed);
            
            prev2 = prev;
            prev = cur;
        }

        return prev;
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