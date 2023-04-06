class Solution {
public:
    // idea : the best we can do is to reduce nums[i] to the average of array nums[0, i]
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        
        long long sum = 0, res = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            
            long long cur_avg = ceil((double)sum / (i+1));
            res = max(res, cur_avg); 
        }
        
        return res;   
    }
};