class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0, diff = 0, len = INT_MAX;
        int i = 0, j = 0;
        while(j < n) {
            sum += nums[j];
            
            if(sum < target) {
                ++j;
            }
            else {
                diff = sum - target;
                len = min(len, j-i+1);
                
                while(sum > target) {
                    sum -= nums[i];
                    ++i;
                    
                    if(sum >= target && sum - target < diff) {
                        diff = sum - target;
                        len = min(len, j-i+1);
                    }   
                }
                
                // if(sum == target) len = min(len, j-i+1);
                ++j;    
            }
        }
        
        return (len == INT_MAX ? 0 : len);
    }
};  