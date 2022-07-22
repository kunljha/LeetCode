class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        
        func(0, 0, arr, target, ans, subset);
        
        return ans;
    }
    
    void func(int idx, int sum, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &subset) {
        if(sum == target) {
            ans.push_back(subset);
            return;
        }
        
        if(idx == arr.size() || sum > target) return;
        
        subset.push_back(arr[idx]);
        func(idx, sum + arr[idx], arr, target, ans, subset);
        
        subset.pop_back();
        func(idx+1, sum, arr, target, ans, subset);
    }
};