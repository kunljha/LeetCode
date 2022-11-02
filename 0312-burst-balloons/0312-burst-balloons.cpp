class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return fun(1, n, nums, dp);
    }
    
    int fun(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maximal = -1e9;
        for(int ind = i; ind <= j; ++ind) {
            int coins = 
                nums[i-1]*nums[ind]*nums[j+1]
                + fun(i, ind-1, nums, dp)
                + fun(ind+1, j, nums, dp);
            
            maximal = max(maximal, coins);
        }
        
        return dp[i][j] = maximal;
    } 
};