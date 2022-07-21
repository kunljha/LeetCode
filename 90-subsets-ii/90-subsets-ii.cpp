class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> subset;
        
        func(0, nums, subset, ans);
        
        return ans;
    }
    
    void func(int idx, vector<int> &nums, vector<int> &subset, vector<vector<int>> &ans) {
        ans.push_back(subset);
        
        for(int i = idx; i < nums.size(); ++i) {
            if(i != idx and nums[i] == nums[i-1]) continue;
        
            subset.push_back(nums[i]);
            func(i+1, nums, subset, ans);

            subset.pop_back();
        }
    }
};