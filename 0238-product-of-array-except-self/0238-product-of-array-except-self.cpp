class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> begin(n), end(n);
        
        begin[0] = 1, end[n-1] = 1;
        for(int i = 1; i < n; ++i) {
            begin[i] = begin[i-1] * nums[i-1];
        }
        
        for(int i = n-2; i >= 0; --i) {
            end[i] = end[i+1] * nums[i+1];
        }
        
        vector<int> ans(n);
        for(int i = 0; i < n; ++i) {
            ans[i] = begin[i] * end[i];
        }
        
        return ans;
    }
};