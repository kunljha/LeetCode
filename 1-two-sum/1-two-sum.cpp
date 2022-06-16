class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> table;
        for(int i = 0; i < nums.size(); i++){
            if(table.find(target - nums[i]) != table.end()){
                ans.push_back(i);
                ans.push_back(table[target - nums[i]]);
            }
            else {
                table[nums[i]] = i;
            }
        }
        return ans;
    }
};