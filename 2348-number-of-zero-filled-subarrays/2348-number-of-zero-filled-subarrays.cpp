class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        
        int i = 0, j = 0;
        while(i <= j && j < n) {
            if(nums[j] == 0) {
                cnt += j-i+1;
                ++j;
            }
            else {
                i = ++j;
            }
        }
        
        return cnt;     
    }
};