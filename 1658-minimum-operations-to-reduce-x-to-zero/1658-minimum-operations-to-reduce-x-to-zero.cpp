class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), totSum = 0;
        for(int &num : nums) totSum += num;
        
        if(totSum == x) return n;
        
        unordered_map<int, int> ump;
        ump[0] = -1;
        
        int k = totSum - x; // idea: longest subarray of sum k
        int len = -1; // len is assigned as -1, acts as a flag if no subarray of sum k is found
       
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            
            if(ump.count(sum - k))
                len = max(len, i-ump[sum-k]);
            
            ump[sum] = i;
        }
        
        return (len == -1 ? -1 : n-len);
    }
};