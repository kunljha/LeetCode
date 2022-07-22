class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        vector<int> subset;
        
        func(0, 0, nums, target, subset, ans);
        
        return ans;
    }
    
    void func(int idx, int sum, vector<int> &nums, int target, vector<int> &subset, vector<vector<int>> &ans) {
        if(sum == target) {
            ans.push_back(subset);
            return;
        }
        
        for(int i = idx; i < nums.size(); ++i) {
            if(i != idx and nums[i] == nums[i-1]) continue; // skip duplicates
            
            if(sum + nums[i] > target) break;
            
            subset.push_back(nums[i]);
            func(i+1, sum+nums[i], nums, target, subset, ans);

            subset.pop_back();
        }
    }
};