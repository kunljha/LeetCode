class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> table;
        
        for(int &x: nums) {
            if(table.find(x) != table.end())
                return true;
            else
                table.insert({x, true});
        }
        
        return false;
    }
};