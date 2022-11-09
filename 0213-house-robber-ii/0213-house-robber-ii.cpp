class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        
        vector<int> dp1(n-1, 0);
        vector<int> dp2(n, 0);
        
        // base-case
        dp1[0] = nums[0];
        dp2[1] = nums[1];
        
        // filling dp1
        for(int ind = 1; ind < n-1; ++ind) {
            int notPick = 0 + dp1[ind-1];
            int pick = nums[ind];
            if(ind > 1) pick += dp1[ind-2];

            dp1[ind] = max(notPick, pick);
        }
        
        // filling dp2
        for(int ind = 2; ind < n; ++ind) {
            int notPick = 0 + dp2[ind-1];
            int pick = nums[ind] + dp2[ind-2];

            dp2[ind] = max(notPick, pick);
        }
        
        return max(dp1[n-2], dp2[n-1]);
    }
    
//     int fun1(int ind, vector<int> &nums, vector<int> &dp1) {
//         if(ind < 0) return 0;
//         if(ind == 0) return nums[0];
        
//         if(dp1[ind] != -1) return dp1[ind];
        
//         int notPick = 0 + fun1(ind-1, nums, dp1);
//         int pick = nums[ind] + fun1(ind-2, nums, dp1);
        
//         return dp1[ind] = max(notPick, pick);
//     }
    
//     int fun2(int ind, vector<int> &nums, vector<int> &dp2) {
//         if(ind <= 0) return 0;
//         if(ind == 1) return nums[1];
        
//         if(dp2[ind] != -1) return dp2[ind];
        
//         int notPick = 0 + fun2(ind-1, nums, dp2);
//         int pick = nums[ind] + fun2(ind-2, nums, dp2);
        
//         return dp2[ind] = max(notPick, pick);
//     }
};