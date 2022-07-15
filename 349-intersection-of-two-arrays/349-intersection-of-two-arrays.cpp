class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash;
        
        vector<int> ans;
        
        for(int &num : nums1)
            hash.insert(num);
        
        for(int &num : nums2) {
            if(hash.find(num) != hash.end() && find(ans.begin(), ans.end(), num) == ans.end())
                ans.push_back(num);  
        }
        
        return ans;
    }
};