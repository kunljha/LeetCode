class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash;
        
        vector<int> ans;
        
        for(int &num : nums1)
            hash.insert(num);
        
        for(int &num : nums2) {
            if(hash.count(num) && count(ans.begin(), ans.end(), num) == 0)
                ans.push_back(num);  
        }
        
        return ans;
    }
};