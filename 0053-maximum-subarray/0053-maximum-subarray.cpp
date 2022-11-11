class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        // space-optimised-dp
        vector<int> front(2, 0), cur(2, 0);
        
        // base-case
        front[0] = -1e9;
        front[1] = 0;
        
        for(int i = n-1; i >= 0; --i) {
            int pick = nums[i] + front[1];
            int stop = 0; // means stop picking and return with cur sum
            cur[1] = max(stop, pick);
            
            
            int notPick = 0 + front[0];
            pick = nums[i] + front[1];
            cur[0] = max(notPick, pick); 
            
            front = cur;
        }
            
        return front[0];     
    }
};