class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        
        vector<int> ans;
        
        for(int& x1 : nums1)
            ++count[x1];
        
        for(int& x2 : nums2) {
            if(count[x2] > 0) {
                --count[x2];
                ans.push_back(x2);
            }
        }
        
        return ans;
    }
};