class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2);
        unordered_map<int, int> table;
        for(int i = 0; i < nums.size(); i++){
            if(table.find(target - nums[i]) != table.end()){
                v[0] = i;
                v[1] = table[target - nums[i]];
            }
            else {
                table[nums[i]] = i;
            }
        }
        return v;
    }
};