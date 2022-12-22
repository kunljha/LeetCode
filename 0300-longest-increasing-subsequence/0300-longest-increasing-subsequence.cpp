class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        // base-case
        // for(int prev_ind = -1; prev_ind < n; ++prev_ind) {
        //     dp[n][prev_ind+1] = 0;
        // }
        //
        
        for(int ind = n-1; ind >= 0; --ind) {
            for(int prev_ind = n-1; prev_ind >= -1; --prev_ind) {
                int notPick = 0 + dp[ind+1][prev_ind+1];
                int pick = 0;
                if(prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    pick = 1 + dp[ind+1][ind+1];
                }

                dp[ind][prev_ind+1] = max(notPick, pick);   
            }  
        }
      
        return dp[0][0];
    }
    
//     int fun(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp) {
//         if(ind == nums.size()) return 0;
        
//         if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        
//         int notPick = 0 + fun(ind+1, prev_ind, nums, dp);
//         int pick = 0;
//         if(prev_ind == -1 || nums[ind] > nums[prev_ind]) {
//             pick = 1 + fun(ind+1, ind, nums, dp);
//         }
        
//         return dp[ind][prev_ind+1] = max(notPick, pick);
//     }
};