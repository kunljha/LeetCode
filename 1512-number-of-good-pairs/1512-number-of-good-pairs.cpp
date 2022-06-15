class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        vector<int> count(101, 0);
        
        for(int &x : nums)
            ++count[x]; // counting frequecy of elements in nums
        
        for(int &n : count) {
            ans += (n*(n-1))/2;
        }
        
        return ans;
    }
};