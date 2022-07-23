class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> permutation;
        vector<bool> visited(nums.size(), false);
            
        func(nums, visited, permutation, ans);
        
        return ans;
    }
    
    void func(vector<int> &nums, vector<bool> &visited, vector<int> &permutation, vector<vector<int>> &ans) {
        if(permutation.size() == nums.size()) {
            ans.push_back(permutation);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            if(!visited[i]) {
                visited[i] = true;
                permutation.push_back(nums[i]);
            
                func(nums, visited, permutation, ans);
            
                visited[i] = false;
                permutation.pop_back();   
            } 
        }
    }
};