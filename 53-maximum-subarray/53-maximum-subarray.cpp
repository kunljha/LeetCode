class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;
        for(auto x : nums) {
            sum += x;
            maxSum = max(sum, maxSum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};