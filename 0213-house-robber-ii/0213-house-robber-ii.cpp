class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return nums[0]; // corner-case
        
        // vector<int> dp1(n-1, 0);
        // vector<int> dp2(n, 0);
        int prev2, prev;
         
        // for houses : 0 --> n-2
        prev2 = 0, prev = nums[0];
        
        for(int ind = 1; ind < n-1; ++ind) {
            int notPick = 0 + prev;
            int pick = nums[ind];
            if(ind > 1) pick += prev2;

            int cur = max(notPick, pick);
            
            prev2 = prev;
            prev = cur;
        }
        
        int ans1 = prev;
        
        // for houses : 1 --> n-1
        prev2 = 0, prev = nums[1];
        
        for(int ind = 2; ind < n; ++ind) {
            int notPick = 0 + prev;
            int pick = nums[ind] + prev2;

            int cur = max(notPick, pick);
            
            prev2 = prev;
            prev = cur;
        }
        
        int ans2 = prev;
        
        return max(ans1, ans2);
    }
};