class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int totSum  = 0;
        for(int &x : nums)
            totSum += x;
        
        if(totSum % 2 != 0) return false;
        
        int k = totSum / 2;
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        
        return subsetSumK(n-1, k, nums, dp);
    }
    
    bool subsetSumK(int ind, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if(target == 0) return true;
        if(ind == 0) return (nums[0] == target);
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool notPick = subsetSumK(ind-1, target, nums, dp);
        bool pick = false;
        if(nums[ind] <= target) {
            pick = subsetSumK(ind-1, target-nums[ind], nums, dp);
        }
        
        return dp[ind][target] = notPick || pick;
    }
};