class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0];
        
        vector<int> dp1(n-1, -1);
        vector<int> dp2(n, -1);

        return max(fun1(n-2, nums, dp1), fun2(n-1, nums, dp2));
    }
    
    int fun1(int ind, vector<int> &nums, vector<int> &dp1) {
        if(ind < 0) return 0;
        if(ind == 0) return nums[0];
        
        if(dp1[ind] != -1) return dp1[ind];
        
        int notPick = 0 + fun1(ind-1, nums, dp1);
        int pick = nums[ind] + fun1(ind-2, nums, dp1);
        
        return dp1[ind] = max(notPick, pick);
    }
    
    int fun2(int ind, vector<int> &nums, vector<int> &dp2) {
        if(ind <= 0) return 0;
        if(ind == 1) return nums[1];
        
        if(dp2[ind] != -1) return dp2[ind];
        
        int notPick = 0 + fun2(ind-1, nums, dp2);
        int pick = nums[ind] + fun2(ind-2, nums, dp2);
        
        return dp2[ind] = max(notPick, pick);
    }
};