class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> table;
        
        for(int &x: nums) {
            if(table.find(x) != table.end())
                table[x]++;
            else 
                table.insert({x, 1});

        }
        
        for(auto it = table.begin(); it != table.end(); it++) {
            if(it->second > n/2) return it->first;
        }
        
        return -1;
    }
};