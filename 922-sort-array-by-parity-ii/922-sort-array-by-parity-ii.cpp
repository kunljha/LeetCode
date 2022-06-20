class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int i = 0, j = 1, k = 0;
        while(i < n || j < n) {
            if(nums[k]&1) {
                ans[j] = nums[k++];
                j += 2;
            } else {
                ans[i] = nums[k++];
                i += 2;
            }  
        }
        
        return ans;
    }
};