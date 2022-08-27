class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        
        long long goodPairs = 0;
        
        unordered_map<int, int> hash;
        
        for(int i = 0; i < n; ++i) {
            goodPairs += hash[nums[i] - i]; // nums[i] - i == nums[j] - j
            ++hash[nums[i] - i];
        }
        
        return (n*(n-1))/2 - goodPairs;  // nums[i] - i != nums[j] - j
    }
};