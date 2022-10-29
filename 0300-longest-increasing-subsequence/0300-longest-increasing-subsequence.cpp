class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        // base-case
        // for(int last_ind = 0; last_ind <= n; ++last_ind) {
        //     dp[n][last_ind] = 0;
        // }
        
        for(int ind = n-1; ind >= 0; --ind) {
            for(int last_ind = n; last_ind >= 0; --last_ind) {
                int notPick = 0 + dp[ind+1][last_ind];
                int pick = 0;
                if(last_ind == 0 || nums[ind] > nums[last_ind-1]) {
                    pick = 1 + dp[ind+1][ind+1];
                }
                
                dp[ind][last_ind] = max(notPick, pick);
            }
        }
        
        return dp[0][0];
    }
};