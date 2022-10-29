class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return fun(0, -1, nums, dp);
    }
    
    int fun(int ind, int last_ind, vector<int>& nums, vector<vector<int>> &dp) {
        if(ind == nums.size()) return 0;
        
        if(dp[ind][last_ind+1] != -1) return dp[ind][last_ind+1];
        
        int notPick = 0 + fun(ind+1, last_ind, nums, dp);
        int pick = 0;
        if(last_ind == -1 || nums[ind] > nums[last_ind]) {
            pick = 1 + fun(ind+1, ind, nums, dp);
        }
        
        return dp[ind][last_ind+1] = max(notPick, pick);
    }
};