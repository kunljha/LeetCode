class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        
        for(int  i = 0; i < n; ++i)
            totSum += nums[i];
        
        if((totSum - target) < 0 || (totSum - target)%2 != 0) {
            return 0;
        }
        
        return fun(n-1, (totSum-target) / 2, nums);
    }
    
    int fun(int ind, int T, vector<int> &nums) {
        if(ind == 0) {
            if(T == 0 && nums[0] == 0)
                return 2;
            if(T == 0 || T == nums[0])
                return 1;
            
            return 0;
        }
        
        int notPick = fun(ind-1, T, nums);
        int pick = 0;
        if(nums[ind] <= T) {
            pick = fun(ind-1, T-nums[ind], nums);
        }
        
        return notPick + pick;   
    }
};