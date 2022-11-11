class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        // base-case
        dp[n][0] = -1e9;
        dp[n][1] = 0;
        
        for(int i = n-1; i >= 0; --i) {
            for(int mustPick = 0; mustPick <= 1; ++mustPick) {
                if(mustPick) {
                    int pick = nums[i] + dp[i+1][1];
                    int stop = 0; // means stop picking and return with cur sum

                    dp[i][mustPick] = max(stop, pick);
                } else {
                    int notPick = 0 + dp[i+1][0];
                    int pick = nums[i] + dp[i+1][1];

                    dp[i][mustPick] = max(notPick, pick);
                } 
            }
        }
            
        return dp[0][0];     
    }
    
//     int fn(int i, int mustPick, vector<int> &nums, vector<vector<int>> &dp) {
//         if(i == nums.size()) return mustPick ? 0 : -1e9;
        
//         if(dp[i][mustPick] != -1) return dp[i][mustPick];
        
//         if(mustPick) {
//             int pick = nums[i] + fn(i+1, 1, nums, dp);
//             int stop = 0; // means stop picking and return with cur sum
            
//             return dp[i][mustPick] = max(stop, pick);
//         } else {
//             int notPick = 0 + fn(i+1, 0, nums, dp);
//             int pick = nums[i] + fn(i+1, 1, nums, dp);
          
//             return dp[i][mustPick] = max(notPick, pick);
//         } 
//     } 
};