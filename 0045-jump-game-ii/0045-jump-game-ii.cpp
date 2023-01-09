class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxReachable = 0, lastJumpIdx = 0, jumps = 0;
        
        int i = 0;
        while(lastJumpIdx < n-1) {
            maxReachable = max(maxReachable, i + nums[i]);
            
            if(lastJumpIdx == i) {
                lastJumpIdx = maxReachable;
                ++jumps;
            }
            ++i;
        }
        
        return jumps;
    }
};