class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        // greedy approach
        int cur_sum = nums[0], ans = nums[0];
        
        for(int i = 1; i < nums.size(); ++i) {
            cur_sum = max(cur_sum + nums[i], nums[i]);
            
            ans = max(ans, cur_sum);
        }
        
        return ans;    
    }
};