class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        return fun(n-1, nums, dp);
    }
    
    int fun(int i, vector<int> &nums, vector<int> &dp) {
        if(i == 0) return nums[0];
        if(i < 0) return 0;
        
        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + fun(i-2, nums, dp);
        int notPick = 0 + fun(i-1, nums, dp);
        
        return dp[i] = max(pick, notPick);
    }
};